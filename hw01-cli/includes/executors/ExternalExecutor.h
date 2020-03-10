#ifndef HW01_CLI_EXTERNALEXECUTOR_H
#define HW01_CLI_EXTERNALEXECUTOR_H

#include "executors/ICommandExecutor.h"

/// Implementation of running external commands
class ExternalExecutor : public ICommandExecutor {
public:
    /// Runs commands which is not implemented inside the CLI
    Status execute(
            const Command &command,
            StringChannel &inputChannel,
            StringChannel &outputChannel
    ) const override;
};


#endif //HW01_CLI_EXTERNALEXECUTOR_H
