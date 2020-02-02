
#include <iostream>
#include <CommandBuilder.h>
#include <assert.h>
#include <algorithm>

void CommandBuilder::appendToken(const Token &token) {
    tokens.push_back(token);
}

void CommandBuilder::clear() {
    tokens.clear();
}

Command CommandBuilder::buildCommand() const {
    assert(!tokens.empty());
    // TODO: add exceptions

    std::vector<std::string> stringArguments;
    stringArguments.reserve(tokens.size());
    for (auto i = tokens.begin() + 1; i != tokens.end(); i++) {
        stringArguments.push_back(i->asString());
    }

    return Command(
            CommandName(tokens.front().asString()),
            CommandArguments(stringArguments)
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

