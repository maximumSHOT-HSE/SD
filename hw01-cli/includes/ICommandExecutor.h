#ifndef HW01_CLI_UTILEXECUTOR_H
#define HW01_CLI_UTILEXECUTOR_H

#include <Status.h>
#include <CommandArguments.h>
#include <iostream>

class ICommandExecutor {
public:
    virtual Status execute(
            const CommandArguments &commandArguments,
            std::istream &inputStream,
            std::ostream &outputStream
    ) const = 0;

    virtual ~ICommandExecutor() = 0;
};


#endif //HW01_CLI_UTILEXECUTOR_H
