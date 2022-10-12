#ifndef CALCULATOR_PLUS_PLUS_PARSER_H
#define CALCULATOR_PLUS_PLUS_PARSER_H


#include <vector>
#include <stack>
#include "TokenType.h"

class Parser {
private:
    std::vector<Token> tokens;
public:
    std::vector<Token> toPostFix();

    bool validSyntax();

    Parser(std::vector<Token> value);
};


#endif //CALCULATOR_PLUS_PLUS_PARSER_H
