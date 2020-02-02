
#include <iostream>
#include <CommandBuilder.h>
#include <assert.h>
#include <algorithm>

void CommandBuilder::appendToken(const Token &token) {
    parts.push_back(token);
}

void CommandBuilder::clear() {
    parts.clear();
}

Command CommandBuilder::buildCommand() const {
    assert(!parts.empty());
    // TODO: add exceptions

    std::vector<std::string> stringArguments;
    stringArguments.reserve(parts.size());
    for (auto i = parts.begin() + 1; i != parts.end(); i++) {
        stringArguments.push_back(i->asString());
    }

    return Command(
            CommandName(parts.front().asString()),
            CommandArguments(stringArguments)
    );
}

std::string CommandBuilder::buildCommandString() const {
    std::string commandString;
    for (const auto &part : parts) {
        commandString += part.asString();
    }
    return commandString;
}
