#include <stdexcept>
#include "Parser.h"

Token Parser::extract(std::stack<Token> &s) {
    Token numbers = s.top();
    s.pop();
    return numbers;
}

bool Parser::validSyntax() {
    int openParenthesis{0};
    bool isOperation = false;

    if (tokens.empty() ||
        tokens[0].isOperator()) {
        return false;
    }
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == TokenType::empty) {
            continue;
        }
        if (tokens[i].isOperator()) {
            if (isOperation) {
                return false;
            } else {
                isOperation = true;
            }
        } else if (tokens[i].type != TokenType::rightParenthesis) {
            isOperation = false;
        }
        if (i > 0 && tokens[i].type == TokenType::number &&
            tokens[i - 1].type == TokenType::number) {
            return false;
        }
        if (i > 0 && tokens[i].type == TokenType::leftParenthesis &&
            tokens[i - 1].type == TokenType::number) {
            return false;
        }
        if (tokens[i].type == TokenType::leftParenthesis) {
            openParenthesis++;
        }
        if (tokens[i].type == TokenType::rightParenthesis) {
            openParenthesis--;
        }
    }
    return openParenthesis == 0 &&
           !isOperation;
}

std::vector<Token> Parser::toPostFix() {
    if (!validSyntax()) {
        // TODO: handle invalid syntax
        throw std::logic_error("Not Implemented");
    }
    std::vector<Token> numbers;
    std::stack<Token> operators;

    for (auto & token : tokens) {
        if (token.type == TokenType::empty) {
            continue;
        }
        if (token.type == TokenType::number) {
            numbers.push_back(token);
        } else if (token.type == TokenType::leftParenthesis) {
            operators.push(token);
        } else if (token.type == TokenType::rightParenthesis) {
            while (operators.top().type != TokenType::leftParenthesis) {
                numbers.push_back(extract(operators));
            }
            operators.pop();
        } else {
            while (!operators.empty() &&
                   operators.top().precedence >= token.precedence) {
                numbers.push_back(extract(operators));
            }
            operators.push(token);
        }
    }
    while (!operators.empty()) {
        numbers.push_back(extract(operators));
    }
    return numbers;
}
