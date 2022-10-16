#include <iostream>
#include <sstream>
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

void Lexer::tokenize() {
    char nextCharacter = std::cin.peek();

    while (std::cin.good()) {
        if (isdigit(nextCharacter) || nextCharacter == '.') {
            // push_back to tokens
        } else {
            std::cin.get(nextCharacter);
            if (std::isspace(nextCharacter)) {
                while (std::cin.good() && std::isspace(std::cin.peek())) {
                    std::cin.get();
                }
            } else if (validOperator(nextCharacter)) {
                // push_back to tokens
            } else {
                // throw error
            }
        }
    }
}