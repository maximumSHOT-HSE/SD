#include "executors/EchoExecutor.h"

Status EchoExecutor::execute(
        const CommandArguments &commandArguments,
        StringChannel &inputStream,
        StringChannel &outputStream
) const {

    const auto &arguments = commandArguments.asTokensVector();

    size_t upTo = arguments.size();
    while (upTo > 0 && arguments[upTo - 1].getTokenType() == TokenType::SPACE) {
        upTo--;
    }

    for (size_t i = 0; i < upTo; i++) {
        if (arguments[i].getTokenType() == TokenType::SPACE
            && (i == 0u || arguments[i - 1].getTokenType() == TokenType::SPACE)) {
            continue;
        }
        outputStream.write(arguments[i].asString());
    }
    outputStream.write("\n"); // TODO: add cross platform newline character

    // TODO: add exceptions

    return Status();
}
