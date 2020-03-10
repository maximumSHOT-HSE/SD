#ifndef HW01_CLI_EMPTYEXECUTOR_H
#define HW01_CLI_EMPTYEXECUTOR_H

#include "executors/ICommandExecutor.h"

/// Implementation of empty string command
class EmptyExecutor : public ICommandExecutor {
public:
    /// Do nothing
    Status execute(
            const Command &command,
            StringChannel &inputChannel,
            StringChannel &outputChannel
    ) const override;
};


#endif //HW01_CLI_EMPTYEXECUTOR_H
