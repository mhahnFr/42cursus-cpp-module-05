//
// Created by Manuel Hahn on 5/25/22.
//

#include "Form.h"
#include "Bureaucrat.h"

const std::string &Form::getName() const {
    return name;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExecuteGrade() const {
    return executeGrade;
}

bool Form::isSigned() const {
    return hasBeenSigned;
}

Form::Form(): name(), signGrade(150), executeGrade(150), hasBeenSigned(false) {}

Form::Form(const Form &other): name(other.getName()),
                               signGrade(other.getSignGrade()),
                               executeGrade(other.getExecuteGrade()),
                               hasBeenSigned(other.isSigned()) {}

Form::~Form() {}

void Form::beSigned(Bureaucrat &signer) throw(GradeTooLowException) {
    if (signer.getGrade() > getSignGrade()) throw GradeTooLowException();
    hasBeenSigned = true;
}

Form &Form::operator=(const Form &other) {
    if (&other != this) {
        hasBeenSigned = other.isSigned();
    }
    return *this;
}

Form::Form(const std::string &name, const int signGrade, const int executeGrade): name(name),
                                                                                  signGrade(signGrade),
                                                                                  executeGrade(executeGrade),
                                                                                  hasBeenSigned(false) {
    if (signGrade < 1 || executeGrade < 1) throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150) throw GradeTooLowException();
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

std::ostream & operator<<(std::ostream & stream, const Form &self) {
    stream << "Form "             << self.getName()
           << ", sign grade: "    << self.getSignGrade()
           << ", execute grade: " << self.getExecuteGrade()
           << ", is signed: "     << (self.isSigned() ? "true" : "false");
    return stream;
}
