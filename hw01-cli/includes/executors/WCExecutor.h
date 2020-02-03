#ifndef HW01_CLI_WCEXECUTOR_H
#define HW01_CLI_WCEXECUTOR_H

#include <executors/ICommandExecutor.h>
#include <optional>

class WCExecutor : public ICommandExecutor {
public:
    Status execute(
            const CommandArguments &commandArguments,
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


#endif //HW01_CLI_WCEXECUTOR_H
