//
// Created by Manuel Hahn on 5/25/22.
//

#include "Bureaucrat.h"

int main() {
    Form a38("a38", 4, 1);
    Bureaucrat bs[4] = {
            Bureaucrat("Bob", 25),
            Bureaucrat("Alice", 5),
            Bureaucrat("Asterix", 1),
            Bureaucrat("Obelix", 2)
    };
    for (int i = 0; i < 4; ++i) {
        bs[i].signForm(a38);
    }
    Form fs[4] = {
            Form("b65", 25, 2),
            Form("a39", 150, 150),
            a38,
            Form("xxx", 1, 1)
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            bs[j].signForm(fs[i]);
        }
    }
}
