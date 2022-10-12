#ifndef CALCULATOR_PLUS_PLUS_TOKENTYPE_H
#define CALCULATOR_PLUS_PLUS_TOKENTYPE_H

#include <string>

enum class TokenType {
    empty = 'e',
    number = 'n',
    multiplication = '*',
    division = '/',
    addition = '+',
    subtraction = '-',
    leftParenthesis = '(',
    rightParenthesis = ')'
};

struct Token {
    TokenType type;
    std::string value;
    int precedence;
};

#endif //CALCULATOR_PLUS_PLUS_TOKENTYPE_H
