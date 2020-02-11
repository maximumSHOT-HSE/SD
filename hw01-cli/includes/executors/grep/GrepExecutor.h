#ifndef HW01_CLI_GREPEXECUTOR_H
#define HW01_CLI_GREPEXECUTOR_H

#include <executors/ICommandExecutor.h>
#include <executors/grep/GrepArguments.h>

class GrepExecutor : public ICommandExecutor {
public:
    Status execute(
            const Command &command,
            StringChannel &inputChannel,
            StringChannel &outputChannel
    ) const override;

private:
    Status executeFromChannelMode(
            StringChannel &inputChannel,
            const GrepArguments &arguments
    ) const;
};


#endif //HW01_CLI_GREPEXECUTOR_H
