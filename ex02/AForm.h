//
// Created by Manuel Hahn on 5/25/22.
//

#ifndef EX01_FORM_H
#define EX01_FORM_H


#include <string>

class Bureaucrat;

class AForm {
public:
    AForm();
    AForm(const AForm &);
    AForm(const std::string &name, int signGrade, int executeGrade);
    virtual ~AForm();

    void beSigned(Bureaucrat & signer) throw(GradeTooLowException);
    virtual void execute(const Bureaucrat & executor) const throw(GradeTooLowException) = 0;

    const std::string &getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool isSigned() const;

    AForm & operator=(const AForm &);

    class GradeTooLowException: public std::exception {
    public:
        const char *what() const _NOEXCEPT;
    };

    class GradeTooHighException: public std::exception {
    public:
        const char *what() const _NOEXCEPT;
    };

    class UnsignedException: public std::exception {
    public:
        const char *what() const _NOEXCEPT;
    };

protected:
    void preExecute(const Bureaucrat & executor) const throw(GradeTooLowException);

private:
    const std::string name;
    const int signGrade;
    const int executeGrade;
    bool hasBeenSigned;
};

std::ostream & operator<<(std::ostream & stream, const AForm &self);

#endif //EX01_FORM_H
