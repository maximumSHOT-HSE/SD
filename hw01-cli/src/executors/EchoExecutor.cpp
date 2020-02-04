#include "executors/EchoExecutor.h"

Status EchoExecutor::execute(
        const Command &command,
        StringChannel &inputStream,
        StringChannel &outputStream
) const {

    const auto &arguments = command.getCommandArguments().stripe().asTokensVector();

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
