
#include <Token.h>

TokenType Token::getTokenType() const {
    return tokenType;
}

std::string Token::asString() const {
    return tokenContent;
}

Token::Token(const TokenType &tokenType, const std::string &tokenContent)
        : tokenType(tokenType), tokenContent(tokenContent) {}
