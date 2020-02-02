
#include <CommandBuilder.h>
#include <assert.h>

void CommandBuilder::appendToken(const Token &token) {
    parts.push_back(token);
}

void CommandBuilder::clear() {
    parts.clear();
}

Command CommandBuilder::buildCommand() {
    assert(!parts.empty());
    // TODO: add exceptions

    return Command(
            CommandName(parts.front().asString()),
            CommandArguments(
                    std::vector<std::string>(
                            parts.begin() + 1,
                            parts.end()
                    )
            )
    );
}
