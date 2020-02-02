#include "EchoExecutor.h"

Status EchoExecutor::execute(
        const CommandArguments &commandArguments,
        StringChannel &inputStream,
        StringChannel &outputStream) const {

    for (const auto &argument : commandArguments.asStringsVector()) {
        outputStream.write(argument);
    }

    // TODO: add exceptions

    return Status();
}
