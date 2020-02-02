#ifndef HW01_CLI_ENVIRONMENT_H
#define HW01_CLI_ENVIRONMENT_H

#include <CommandExecutorFactory.h>
#include <Command.h>
#include <EchoExecutor.h>

class Environment {
public:
    Environment();

    const ICommandExecutor &getCommandExecutorByCommandName(
            const CommandName &commandName
    ) const;

private:
    CommandExecutorFactory factory;
    EchoExecutor *echoExecutor;
};

#endif //HW01_CLI_ENVIRONMENT_H
