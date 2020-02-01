#ifndef HW01_CLI_TOKEN_H
#define HW01_CLI_TOKEN_H

enum TokenType {PIPE, SPACE, END, ASSIGN, LITERAL};

class Token {
public:
    TokenType getTokenType() const;

private:
    TokenType tokenType;
};


#endif //HW01_CLI_TOKEN_H
