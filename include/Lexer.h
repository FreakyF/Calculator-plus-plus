#ifndef CALCULATOR_PLUS_PLUS_LEXER_H
#define CALCULATOR_PLUS_PLUS_LEXER_H


#include <vector>
#include "TokenType.h"

class Lexer {
private:

public:
    std::vector<Token> tokens;

    bool validOperator(char character);

    std::string getNumber();

    void tokenize();

    Lexer() {}

    std::vector<Token> getTokens() { return tokens; }
};


#endif //CALCULATOR_PLUS_PLUS_LEXER_H
