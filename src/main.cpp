#include <iostream>
#include "Lexer.h"

int main() {
    Lexer lex;
    lex.tokenize();
    for (const auto &x: lex.tokens) {
        std::cout << x.precedence << " " << x.value << "\n";
    }

    return 0;
}
