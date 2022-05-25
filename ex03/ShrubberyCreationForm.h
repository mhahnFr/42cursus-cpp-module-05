//
// Created by Manuel Hahn on 5/25/22.
//

#ifndef EX02_SHRUBBERYCREATIONFORM_H
#define EX02_SHRUBBERYCREATIONFORM_H


#include "AForm.h"

class ShrubberyCreationForm: public AForm {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &);
    ShrubberyCreationForm(const std::string &target);
    ~ShrubberyCreationForm();

    const std::string &getTarget() const;
    void execute(const Bureaucrat &executor) const throw(GradeTooLowException);

    ShrubberyCreationForm & operator=(const ShrubberyCreationForm &);

private:
    const std::string target;
};


#endif //EX02_SHRUBBERYCREATIONFORM_H
