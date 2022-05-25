//
// Created by Manuel Hahn on 5/25/22.
//

#include <iostream>
#include "RobotomyRequestForm.h"

void RobotomyRequestForm::execute(const Bureaucrat &executor) const throw(GradeTooLowException) {
    AForm::preExecute(executor);
    std::cout << " * Cruel drilling noises * " << std::endl;
    if (arc4random() % 2) {
        std::cout << getTarget() << " robotomized successfully" << std::endl;
    } else {
        std::cout << getTarget() << " could not be robotomized" << std::endl;
    }
}

const std::string &RobotomyRequestForm::getTarget() const {
    return target;
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target(other.getTarget()) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &) {
    // Nothing to be done...
    return *this;
}
