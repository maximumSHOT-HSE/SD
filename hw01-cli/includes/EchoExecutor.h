#ifndef HW01_CLI_ECHOEXECUTOR_H
#define HW01_CLI_ECHOEXECUTOR_H

#include <ICommandExecutor.h>

class EchoExecutor : public ICommandExecutor {
public:
    Status execute(const CommandArguments &commandArguments, StringChannel &inputStream,
                   StringChannel &outputStream) const override;

};


#endif //HW01_CLI_ECHOEXECUTOR_H
