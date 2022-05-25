//
// Created by Manuel Hahn on 5/25/22.
//

#include "AForm.h"
#include "Bureaucrat.h"

const std::string &AForm::getName() const {
    return name;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecuteGrade() const {
    return executeGrade;
}

bool AForm::isSigned() const {
    return hasBeenSigned;
}

AForm::AForm(): name(), signGrade(150), executeGrade(150), hasBeenSigned(false) {}

AForm::AForm(const AForm &other): name(other.getName()),
                                  signGrade(other.getSignGrade()),
                                  executeGrade(other.getExecuteGrade()),
                                  hasBeenSigned(other.isSigned()) {}

AForm::~AForm() {}

void AForm::beSigned(Bureaucrat &signer) throw(GradeTooLowException) {
    if (signer.getGrade() > getSignGrade()) throw GradeTooLowException();
	if (hasBeenSigned) {
		std::cout << *this << " is already signed!" << std::endl;
		return;
	}
    hasBeenSigned = true;
}

AForm &AForm::operator=(const AForm &other) {
    if (&other != this) {
        hasBeenSigned = other.isSigned();
    }
    return *this;
}

AForm::AForm(const std::string &name, const int signGrade, const int executeGrade): name(name),
                                                                                    signGrade(signGrade),
                                                                                    executeGrade(executeGrade),
                                                                                    hasBeenSigned(false) {
    if (signGrade < 1 || executeGrade < 1) throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150) throw GradeTooLowException();
}

void AForm::preExecute(const Bureaucrat &executor) const throw(GradeTooLowException) {
    if (!isSigned()) throw UnsignedException();
    if (executor.getGrade() > getExecuteGrade()) throw GradeTooLowException();
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

std::ostream & operator<<(std::ostream & stream, const AForm &self) {
    stream << "AForm "             << self.getName()
           << ", sign grade: "    << self.getSignGrade()
           << ", execute grade: " << self.getExecuteGrade()
           << ", is signed: "     << (self.isSigned() ? "true" : "false");
    return stream;
}

const char *AForm::UnsignedException::what() const throw() {
    return "Form has not been signed!";
}
