#include <iostream>
#include "Lexer.h"


bool Lexer::validOperator(char character) {
    std::string operators = "*/-+";

    for (char const &c: operators) {
        if (c == character) {
            return true;
        }
    }
    return false;
}
