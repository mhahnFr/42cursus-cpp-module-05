//
// Created by Manuel Hahn on 5/25/22.
//

#include "Bureaucrat.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"

int main() {
    Bureaucrat bs[4] = {
            Bureaucrat("President", 1),
            Bureaucrat("RandomGuy", 150),
            Bureaucrat("Vicepresident", 30),
            Bureaucrat("Bureaucrat", 50)
    };
    RobotomyRequestForm rf("car");
    ShrubberyCreationForm sf("garden");
    PresidentialPardonForm pf("Ultimate killer");

    for (int i = 0; i < 4; ++i) {
        bs[i].signForm(rf);
        bs[i].signForm(sf);
        bs[i].signForm(pf);
    }
    for (int i = 0; i < 4; ++i) {
        bs[i].executeForm(rf);
        bs[i].executeForm(sf);
        bs[i].executeForm(pf);
    }
}
