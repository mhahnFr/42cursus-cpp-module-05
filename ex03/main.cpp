//
// Created by Manuel Hahn on 5/25/22.
//

#include "Bureaucrat.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"

int main() {
    Bureaucrat bs[4] = {
            Bureaucrat("President", 1),
            Bureaucrat("RandomGuy", 150),
            Bureaucrat("Vicepresident", 30),
            Bureaucrat("Bureaucrat", 50)
    };
    Intern intern;
    AForm *fs[4] = {
            intern.makeForm("RobotomyRequestForm", "my car"),
            intern.makeForm("PresidentialPardonForm", "himself"),
            intern.makeForm("NotExistingForm", "intern"),
            intern.makeForm("ShrubberyCreationForm", "church's garden")
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (fs[j] != 0L) {
                bs[i].signForm(*fs[j]);
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (fs[j] != 0L) {
                bs[i].executeForm(*fs[j]);
            }
        }
    }
}
