#include "EchoExecutor.h"

Status EchoExecutor::execute(
        const CommandArguments &commandArguments,
        StringChannel &inputStream,
        StringChannel &outputStream) const {

    bool isFirst = true;
    for (const auto &argument : commandArguments.asStringsVector()) {
        if (!isFirst) {
            outputStream.write(" ");
        } else {
            isFirst = false;
        }
        outputStream.write(argument);
    }
    outputStream.write("\n"); // TODO: add cross platform newline character

    // TODO: add exceptions

    return Status();
}
