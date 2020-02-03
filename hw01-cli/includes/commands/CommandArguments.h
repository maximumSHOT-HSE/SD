#ifndef HW01_CLI_COMMANDARGUMENTS_H
#define HW01_CLI_COMMANDARGUMENTS_H

#include <string>
#include <vector>
#include <Token.h>

class CommandArguments {
public:
    CommandArguments() = default;

    explicit CommandArguments(const std::vector<Token> &argumentTokens);

    std::vector<std::string> asStringsVector() const;

    std::vector<Token> asTokensVector() const;

    size_t size() const;

private:
    std::vector<Token> argumentTokens;
};


#endif //HW01_CLI_COMMANDARGUMENTS_H
