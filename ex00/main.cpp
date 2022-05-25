//
// Created by Manuel Hahn on 5/25/22.
//

#include <iostream>
#include "Bureaucrat.h"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", -1);
    } catch (Bureaucrat::GradeTooHighException &exception) {
        std::cerr << exception.what() << std::endl;
    }
    Bureaucrat bs[3] = {
            Bureaucrat("a", 1),
            Bureaucrat("b", 55),
            Bureaucrat("c", 150)
    };
    for (int i = 0; i < 3; i++) {
        try {
            bs[i].increaseGrade();
            std::cout << bs[i] << std::endl;
            bs[i].decreaseGrade();
            std::cout << bs[i] << std::endl;
            bs[i].decreaseGrade();
            std::cout << bs[i] << std::endl;
        } catch (std::exception &exception) {
            std::cerr << exception.what() << std::endl;
            std::cerr << "Failed with: " << bs[i] << std::endl;
        }
    }
}
