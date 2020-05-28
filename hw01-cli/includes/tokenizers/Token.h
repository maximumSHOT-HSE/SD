#ifndef HW01_CLI_TOKEN_H
#define HW01_CLI_TOKEN_H

#include <string>

enum class TokenType {
    PIPE = 0, SPACE = 1, END = 2, ASSIGN = 3, LITERAL = 4, DOLLAR = 5, QUOTE = 6
};

/// The unit of tokenization process.
class Token {
public:
    explicit Token(const TokenType &tokenType, const std::string &tokenContent = "");

    TokenType getTokenType() const;

    /// Creates the string representation of token.
    const std::string &asString() const;

    /// Checks whether the string representation is empty or not
    bool empty() const;

private:
    TokenType tokenType;
    std::string tokenContent;
};


#endif //HW01_CLI_TOKEN_H
