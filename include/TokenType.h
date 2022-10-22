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

    Token(TokenType t, std::string v) : type(t), value(v), precedence(0) {
        if (t == TokenType::division || t == TokenType::multiplication) {
            precedence = 2;
        }
        if (t == TokenType::addition || t == TokenType::subtraction) {
            precedence = 1;
        }
    };
};

#endif //CALCULATOR_PLUS_PLUS_TOKENTYPE_H
