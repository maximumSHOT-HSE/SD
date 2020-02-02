#ifndef HW01_CLI_UTILEXECUTOR_H
#define HW01_CLI_UTILEXECUTOR_H

#include <Status.h>
#include <CommandArguments.h>
#include <StringChannel.h>

class ICommandExecutor {
public:
    virtual Status execute(
            const CommandArguments &commandArguments,
            StringChannel &inputStream,
            StringChannel &outputStream
    ) const = 0;

    virtual ~ICommandExecutor() = default;
};


#endif //HW01_CLI_UTILEXECUTOR_H
