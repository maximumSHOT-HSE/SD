#include <commands/CommandArguments.h>

std::vector<std::string> CommandArguments::asStringsVector() const {
    std::vector<std::string> stringTokens;
    for (const auto &token : argumentTokens) {
        stringTokens.push_back(token.asString());
    }
    return stringTokens;
}

CommandArguments::CommandArguments(const std::vector<Token> &argumentTokens)
        : argumentTokens(argumentTokens) {}

std::vector<Token> CommandArguments::asTokensVector() const {
    return argumentTokens;
}

size_t CommandArguments::size() const {
    return argumentTokens.size();
}
