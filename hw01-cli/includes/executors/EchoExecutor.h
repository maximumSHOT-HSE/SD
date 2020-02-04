#ifndef HW01_CLI_ECHOEXECUTOR_H
#define HW01_CLI_ECHOEXECUTOR_H

#include <executors/ICommandExecutor.h>

class EchoExecutor : public ICommandExecutor {
public:
    Status execute(
            const Command &command,
            StringChannel &inputStream,
            StringChannel &outputStream
    ) const override;

};


#endif //HW01_CLI_ECHOEXECUTOR_H
