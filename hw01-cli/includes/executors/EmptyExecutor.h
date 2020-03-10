#ifndef HW01_CLI_EMPTYEXECUTOR_H
#define HW01_CLI_EMPTYEXECUTOR_H

#include "executors/ICommandExecutor.h"

class EmptyExecutor : public ICommandExecutor {
public:
    Status execute(
            const Command &command,
            StringChannel &inputChannel,
            StringChannel &outputChannel
    ) const override;
};


#endif //HW01_CLI_EMPTYEXECUTOR_H
