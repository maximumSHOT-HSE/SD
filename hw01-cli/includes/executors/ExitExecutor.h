#ifndef HW01_CLI_EXITEXECUTOR_H
#define HW01_CLI_EXITEXECUTOR_H

#include <executors/ICommandExecutor.h>

class ExitExecutor : public ICommandExecutor {
public:
    Status execute(
            const Command &command,
            StringChannel &inputStream,
            StringChannel &outputStream
    ) const override;
};


#endif //HW01_CLI_EXITEXECUTOR_H
