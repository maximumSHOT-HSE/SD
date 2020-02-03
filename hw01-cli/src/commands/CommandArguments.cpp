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

size_t CommandArguments::countTokensWithType(const TokenType &tokenType) const {
    size_t count = 0;
    for (const auto &token : argumentTokens) {
        if (token.getTokenType() == tokenType) {
            count++;
        }
    }
    return count;
}

CommandArguments CommandArguments::stripe() const {
    return this->lstripe().rstripe();
}

CommandArguments CommandArguments::lstripe() const {
    std::vector<Token> arguments = argumentTokens;
    size_t l = 0;
    while (l < arguments.size() && arguments[l].getTokenType() == TokenType::SPACE) {
        l++;
    }
    arguments.erase(arguments.begin(), arguments.begin() + l);
    return CommandArguments(arguments);
}

CommandArguments CommandArguments::rstripe() const {
    std::vector<Token> arguments = argumentTokens;
    size_t r = arguments.size();
    while (r > 0u && arguments[r - 1].getTokenType() == TokenType::SPACE) {
        r--;
    }
    arguments.erase(arguments.begin() + r, arguments.end());
    return CommandArguments(arguments);
}
