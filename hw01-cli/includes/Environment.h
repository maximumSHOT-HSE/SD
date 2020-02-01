#ifndef HW01_CLI_ENVIRONMENT_H
#define HW01_CLI_ENVIRONMENT_H

#include <CommandExecutorFactory.h>
#include <Command.h>

class Environment {
public:
    const CommandExecutor &getCommandExecutorByCommandName(
            const CommandName &commandName
    ) const;

    void registerExecutor(
            const CommandName &commandName,
            const CommandExecutor &commandExecutor
    );

private:
    CommandExecutorFactory factory;
};


#endif //HW01_CLI_ENVIRONMENT_H
