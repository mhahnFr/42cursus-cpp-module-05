//
// Created by Manuel Hahn on 5/25/22.
//

#include "Bureaucrat.h"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, const int& grade) : name(name), grade(grade) {
    if (grade < 1) throw GradeTooHighException("Constructing " + name + " with grade " + std::to_string(grade) + ": too high!");
    if (grade > 150) throw GradeTooLowException("Constructing " + name + " with grade " + std::to_string(grade) + ": too low!");
}

Bureaucrat::Bureaucrat(): name(), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.getName()), grade(other.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (&other != this) {
        grade = other.getGrade();
    }
    return *this;
}

const std::string &Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::increaseGrade() throw(GradeTooHighException) {
    if (grade - 1 < 1) throw GradeTooHighException("Increasing grade of " + getName() + " with grade " + std::to_string(getGrade()) + ": too high!");
    --grade;
}

void Bureaucrat::decreaseGrade() throw(GradeTooLowException) {
    if (grade + 1 > 150) throw GradeTooLowException("Decreasing grade of " + getName() + " with grade " + std::to_string(getGrade()) + ": too low!");
    ++grade;
}

std::ostream & operator<<(std::ostream &stream, const Bureaucrat & self) {
    stream << self.getName() << ", bureaucrat grade " << self.getGrade() << ".";
    return stream;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &cause): std::exception(), cause(cause) {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return cause.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(): std::exception(), cause() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &other) _NOEXCEPT: std::exception(), cause(other.what()) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}

Bureaucrat::GradeTooLowException::GradeTooLowException(): std::exception(), cause() {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return cause.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &cause): std::exception(), cause(cause) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &other) _NOEXCEPT: std::exception(), cause(other.what()) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
