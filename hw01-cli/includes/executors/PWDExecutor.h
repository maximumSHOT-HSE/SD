#ifndef HW01_CLI_PWDEXECUTOR_H
#define HW01_CLI_PWDEXECUTOR_H

#include <executors/ICommandExecutor.h>

class PWDExecutor : public ICommandExecutor {
public:
    Status execute(
            const CommandArguments &commandArguments,
            StringChannel &inputStream,
            StringChannel &outputStream
    ) const override;
};


#endif //HW01_CLI_PWDEXECUTOR_H
