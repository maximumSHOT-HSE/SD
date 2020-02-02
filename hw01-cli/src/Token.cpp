
#include <Token.h>

TokenType Token::getTokenType() const {
    return tokenType;
}

std::string Token::asString() const {
    return tokenContent;
}
