#ifndef HW01_CLI_UTILEXECUTOR_H
#define HW01_CLI_UTILEXECUTOR_H

#include <Status.h>
#include <commands/Command.h>
#include <channels/StringChannel.h>

class ICommandExecutor {
public:
    virtual Status execute(
            const Command &command,
            StringChannel &inputChannel,
            StringChannel &outputChannel
    ) const = 0;

    virtual ~ICommandExecutor() = default;
};


#endif //HW01_CLI_UTILEXECUTOR_H
