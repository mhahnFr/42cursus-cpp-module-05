//
// Created by Manuel Hahn on 5/25/22.
//

#ifndef EX02_ROBOTOMYREQUESTFORM_H
#define EX02_ROBOTOMYREQUESTFORM_H


#include "AForm.h"

class RobotomyRequestForm: public AForm {
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &);
    RobotomyRequestForm(const std::string & target);
    ~RobotomyRequestForm();

    void execute(const Bureaucrat &executor) const throw(GradeTooLowException);
    const std::string &getTarget() const;

    RobotomyRequestForm & operator=(const RobotomyRequestForm &);

private:
    const std::string target;
};


#endif //EX02_ROBOTOMYREQUESTFORM_H
