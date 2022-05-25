//
// Created by Manuel Hahn on 5/25/22.
//

#ifndef EX01_FORM_H
#define EX01_FORM_H


#include <string>

class Bureaucrat;

class Form {
public:
    Form();
    Form(const Form &);
    Form(const std::string &name, int signGrade, int executeGrade);
    ~Form();

    void beSigned(Bureaucrat & signer) throw(GradeTooLowException);

    const std::string &getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool isSigned() const;

    Form & operator=(const Form &);

    class GradeTooLowException: public std::exception {
    public:
        const char *what() const _NOEXCEPT;
    };

    class GradeTooHighException: public std::exception {
    public:
        const char *what() const _NOEXCEPT;
    };

private:
    const std::string name;
    const int signGrade;
    const int executeGrade;
    bool hasBeenSigned;
};

std::ostream & operator<<(std::ostream & stream, const Form &self);

#endif //EX01_FORM_H
