#ifndef HW01_CLI_CATEXECUTOR_H
#define HW01_CLI_CATEXECUTOR_H

#include "executors/ICommandExecutor.h"

#include <optional>

class CatExecutor : public ICommandExecutor {
public:
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
