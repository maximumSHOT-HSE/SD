#include <executors/ExitExecutor.h>

#include <assert.h>

Status ExitExecutor::execute(
        const Command &command,
        StringChannel &inputStream,
        StringChannel &outputStream
) const {
    int goodArgumentsCount = 0, exitCode = 0;
    for (const auto &argument : command.getCommandArguments().asTokensVector()) {
        const auto &type = argument.getTokenType();
        if (type != TokenType::END && type != TokenType::SPACE) {
            goodArgumentsCount++;
            assert(goodArgumentsCount <= 1); // Too Many Arguments
            // try
            exitCode = std::stoi(argument.asString());
        }
    }
    Status status;
    status.setExitStatus(ExitStatus::EXIT);
    status.setExitCode(exitCode);
    return status;
}
