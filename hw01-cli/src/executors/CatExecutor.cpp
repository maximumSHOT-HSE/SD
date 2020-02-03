#include "executors/CatExecutor.h"
#include <assert.h>
#include <algorithm>
#include <fstream>
#include <executors/CatExecutor.h>
#include <cctype>


Status CatExecutor::execute(
        const CommandArguments &commandArguments,
        StringChannel &inputStream,
        StringChannel &outputStream
) const {
    if (commandArguments.countTokensWithType(TokenType::LITERAL) > 0) {
        this->executeAtLeastOneArgumentMode(commandArguments, inputStream, outputStream);
    } else {
        this->executeNoArgumentsMode(commandArguments, inputStream, outputStream);
    }
}

Status CatExecutor::executeNoArgumentsMode(
        const CommandArguments &commandArguments,
        StringChannel &inputChannel,
        StringChannel &outputChannel
) const {
    std::string buffer;
    while (!inputChannel.empty()) {
        buffer = inputChannel.read();
        outputChannel.write(buffer);
    }
    return Status();
}

Status CatExecutor::executeAtLeastOneArgumentMode(
        const CommandArguments &commandArguments,
        StringChannel &inputChannel,
        StringChannel &outputChannel
) const {

    const auto &arguments = commandArguments.asTokensVector();

    for (const auto &argument : arguments) {
        if (argument.getTokenType() != TokenType::LITERAL) {
            continue;
        }
        std::ifstream fin(argument.asString()); // TODO: add exceptions
        for (char c; fin.get(c);) {
            outputChannel.write(c);
        }
    }

    return Status();
}
