#ifndef CALCULATOR_PLUS_PLUS_PARSER_H
#define CALCULATOR_PLUS_PLUS_PARSER_H


#include <vector>
#include <stack>
#include "TokenType.h"

class Parser {
private:
    std::vector<Token> tokens;
public:
    Token extract(std::stack<Token> &s);

    bool validSyntax();

    Parser(std::vector<Token> const &value) : tokens(value) {};

    std::vector<Token> toPostFix();

};


#endif //CALCULATOR_PLUS_PLUS_PARSER_H
