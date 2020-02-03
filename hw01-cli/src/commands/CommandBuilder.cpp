#include <iostream>
#include <commands/CommandBuilder.h>
#include <assert.h>
#include <algorithm>

void CommandBuilder::appendToken(const Token &token) {
    if (!token.empty()) {
        tokens.push_back(token);
    }
}

void CommandBuilder::clear() {
    tokens.clear();
}

Command CommandBuilder::buildCommand() const {
    assert(!tokens.empty());
    // TODO: add exceptions

    return Command(
            CommandName(tokens.front().asString()),
            CommandArguments(std::vector<Token>(tokens.begin() + 1, tokens.end()))
    );
}

const std::vector<Token> &CommandBuilder::getTokens() const {
    return tokens;
}

std::string CommandBuilder::buildCommandString() const {
    std::string commandString;
    for (const auto &token : tokens) {
        commandString += token.asString();
    }
    return commandString;
}

