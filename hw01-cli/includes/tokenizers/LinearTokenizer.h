#ifndef HW01_CLI_LINEARTOKENIZER_H
#define HW01_CLI_LINEARTOKENIZER_H

#include <tokenizers/ITokenizer.h>
#include <unordered_map>

class LinearTokenizer : public ITokenizer {
public:
    Token nextToken() override;

    bool hasNextToken() override;

    void append(const std::string &s) override;

    void clear() override;

private:
    std::string s = "";
    int pointer = 0;

    std::unordered_map<char, Token> specialSymbols = {
            {'|', Token(TokenType::PIPE, "|")},
            {'=', Token(TokenType::ASSIGN, "=")},
            {'$', Token(TokenType::DOLLAR, "$")}
    };
};


#endif //HW01_CLI_LINEARTOKENIZER_H
