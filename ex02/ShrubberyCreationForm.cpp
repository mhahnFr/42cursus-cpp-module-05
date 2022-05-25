//
// Created by Manuel Hahn on 5/25/22.
//

#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.h"

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const throw(GradeTooLowException) {
    AForm::preExecute(executor);
    std::ofstream os;
    os.open(getTarget() + "_shrubbery");
    if (!os.is_open()) {
        std::cerr << "Fatal error: Could not create file!" << std::endl;
        return;
    }
    os << "                                                /\\          \n"
          "              ./------\\.                    ,:'|  |':,      \n"
          "            ./          \\,               .:'   |  |   ':.   \n"
          "            |            |                  .:'|  |':.      \n"
          "             \\          /'               .:'   |  |   ':.   \n"
          "              '\\-+  +-/                 '   .:'|  |':.   '  \n"
          "                 |  |                    .:'   |  |   ':.   \n"
          "                 |  |                 .:'   .:'|  |':.   ':.\n"
          "                 |  |                    .:'   |  |   ':.   \n"
          "              _--+  +--_              .:'      |  |      ':.\n"
          "                                               |__|         \n";
    os.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target(other.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &) {
    // Nothing to be done...
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), target(target) {}

const std::string &ShrubberyCreationForm::getTarget() const {
    return target;
}
