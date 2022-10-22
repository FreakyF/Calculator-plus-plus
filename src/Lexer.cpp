#include <iostream>
#include "Lexer.h"

bool Lexer::validOperator(char character) {
    std::string operators = "*/-+()";

    for (char const &c: operators) {
        if (c == character) {
            return true;
        }
    }
    return false;
}

std::string Lexer::getNumber() {
    std::string number;
    bool isDecimal = false;
    char nextCharacter;

    while (std::cin.good()) {
        nextCharacter = std::cin.peek();
        if (nextCharacter != '.' && !isdigit(nextCharacter)) {
            break;
        }
        nextCharacter = std::cin.get();

        if (nextCharacter == '.') {
            if (isDecimal) {
                // TODO: handle multiple dot situation - throw exception
                throw std::logic_error("Not Implemented");
            } else {
                isDecimal = true;
            }
        }
        number += nextCharacter;
    }
    return number;
}

void Lexer::tokenize() {
    char nextCharacter = std::cin.peek();

    while (std::cin.good()) {
        std::cin.get(nextCharacter);
        if (nextCharacter == '\n') {
            break;
        }
        if (isdigit(nextCharacter) || nextCharacter == '.') {
            tokens.push_back(Token(TokenType(TokenType::number), {nextCharacter}));
        } else {

            if (std::isspace(nextCharacter)) {
                while (std::cin.good() && std::isspace(std::cin.peek())) {
                    std::cin.get();
                }
            } else if (validOperator(nextCharacter)) {
                tokens.push_back(Token(TokenType(nextCharacter), {nextCharacter}));

            } else {
                // TODO: handle invalid character situation
                throw std::logic_error("Not Implemented");
            }
        }
    }
}
