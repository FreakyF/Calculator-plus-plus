#ifndef CALCULATOR_PLUS_PLUS_LEXER_H
#define CALCULATOR_PLUS_PLUS_LEXER_H


#include <vector>
#include "TokenType.h"

class Lexer {
private:
    std::vector<Token> tokens;
public:

    bool validOperator();

    void tokenize();

    Lexer(std::string str);

    std::vector<Token> getTokens();
};


#endif //CALCULATOR_PLUS_PLUS_LEXER_H
