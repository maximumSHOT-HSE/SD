#ifndef HW01_CLI_CATEXECUTOR_H
#define HW01_CLI_CATEXECUTOR_H

#include "executors/ICommandExecutor.h"

#include <optional>

/// Implementation of cat command
class CatExecutor : public ICommandExecutor {
public:
    /// Takes bytes from output of previous pipe or from files which are arguments of the command, writes this bytes
    /// into output channel
    Status execute(
            const Command &command,
            StringChannel &inputStream,
            StringChannel &outputStream
    ) const override;
private:
    Status executeNoArgumentsMode(
            const CommandArguments &commandArguments,
            StringChannel &inputChannel,
            StringChannel &outputChannel
    ) const;

    Status executeAtLeastOneArgumentMode(
            const CommandArguments &commandArguments,
            StringChannel &inputChannel,
            StringChannel &outputChannel
    ) const;
};


#endif //HW01_CLI_CATEXECUTOR_H
