//
// Created by Manuel Hahn on 5/25/22.
//

#ifndef EX00_BUREAUCRAT_H
#define EX00_BUREAUCRAT_H


#include <string>
#include <iostream>
#include "AForm.h"

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &);
    Bureaucrat(const std::string &name, const int& grade);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;
    void increaseGrade() throw(GradeTooHighException);
    void decreaseGrade() throw(GradeTooLowException);
    void signForm(AForm &) _NOEXCEPT;
    void executeForm(const AForm &) _NOEXCEPT;

    Bureaucrat & operator=(const Bureaucrat &);

class GradeTooHighException: public std::exception {
public:
    GradeTooHighException(const std::string &cause);
    GradeTooHighException();
    GradeTooHighException(const GradeTooHighException &) _NOEXCEPT;
    ~GradeTooHighException() _NOEXCEPT;

    const char *what() const _NOEXCEPT;

private:
    const std::string cause;
};
class GradeTooLowException: public std::exception {
public:
    GradeTooLowException(const std::string &cause);
    GradeTooLowException();
    GradeTooLowException(const GradeTooLowException &) _NOEXCEPT;
    ~GradeTooLowException() _NOEXCEPT;

    const char *what() const _NOEXCEPT;

private:
    const std::string cause;
};

private:
    const std::string name;
    int grade;
};

std::ostream & operator<<(std::ostream &stream, const Bureaucrat &self);

#endif //EX00_BUREAUCRAT_H
