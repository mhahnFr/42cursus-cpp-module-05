//
// Created by Manuel Hahn on 5/25/22.
//

#include <iostream>
#include "PresidentialPardonForm.h"

const std::string &PresidentialPardonForm::getTarget() const {
    return target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const throw(GradeTooLowException) {
    AForm::preExecute(executor);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), target(other.getTarget()) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &) {
    // Nothing to be done here...
    return *this;
}
