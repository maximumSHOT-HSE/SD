#ifndef HW01_CLI_TOKEN_H
#define HW01_CLI_TOKEN_H

#include <string>

enum TokenType {PIPE, SPACE, END, ASSIGN, LITERAL};

class Token {
public:
    TokenType getTokenType() const;

    std::string asString() const;

private:
    TokenType tokenType;
    std::string tokenContent;
};


#endif //HW01_CLI_TOKEN_H
