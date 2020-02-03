#ifndef HW01_CLI_CATEXECUTOR_H
#define HW01_CLI_CATEXECUTOR_H

#include <executors/ICommandExecutor.h>

class CatExecutor : public ICommandExecutor {
public:
    Status execute(
            const CommandArguments &commandArguments,
            StringChannel &inputStream,
            StringChannel &outputStream
    ) const override;

};


#endif //HW01_CLI_CATEXECUTOR_H
