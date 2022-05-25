//
// Created by Manuel Hahn on 5/25/22.
//

#ifndef EX02_PRESIDENTIALPARDONFORM_H
#define EX02_PRESIDENTIALPARDONFORM_H


#include "AForm.h"

class PresidentialPardonForm: public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &);
    PresidentialPardonForm(const std::string & target);
    ~PresidentialPardonForm();

    void execute(const Bureaucrat &executor) const throw(GradeTooLowException);
    const std::string &getTarget() const;

    PresidentialPardonForm & operator=(const PresidentialPardonForm &);

private:
    const std::string target;
};


#endif //EX02_PRESIDENTIALPARDONFORM_H
