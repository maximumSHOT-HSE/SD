#ifndef HW01_CLI_EXTERNALEXECUTOR_H
#define HW01_CLI_EXTERNALEXECUTOR_H

#include "executors/ICommandExecutor.h"

class ExternalExecutor : public ICommandExecutor {
public:
    Status execute(
            const Command &command,
            StringChannel &inputChannel,
            StringChannel &outputChannel
    ) const override;
};


#endif //HW01_CLI_EXTERNALEXECUTOR_H
