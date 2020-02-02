#include "EchoExecutor.h"

Status EchoExecutor::execute(
        const CommandArguments &commandArguments,
        StringChannel &inputStream,
        StringChannel &outputStream) const {

    const auto &arguments = commandArguments.asTokensVector();
    for (size_t i = 0; i < arguments.size(); i++) {
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
