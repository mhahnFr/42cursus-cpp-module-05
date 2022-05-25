//
// Created by Manuel Hahn on 5/25/22.
//

#ifndef EX03_INTERN_H
#define EX03_INTERN_H


#include "AForm.h"

class Intern {
public:
    Intern();
    Intern(const Intern &);
    ~Intern();

    AForm * makeForm(const std::string &name, const std::string &target);

    Intern & operator=(const Intern &);
};


#endif //EX03_INTERN_H
