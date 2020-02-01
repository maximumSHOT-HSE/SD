#ifndef HW01_CLI_UTILEXECUTORFACTORY_H
#define HW01_CLI_UTILEXECUTORFACTORY_H

#include <string>
#include <CommandExecutor.h>
#include <CommandName.h>
#include <unordered_map>

class CommandExecutorFactory {
private:
    void registerExecutor(
            const CommandName &commandName,
            const CommandExecutor &commandExecutor
    );

    const CommandExecutor &getCommandExecutorByCommandName(
            const CommandName &commandName
    ) const;

private:
    std::unordered_map<CommandName, CommandExecutor> nameToExecutorMap;
};


#endif //HW01_CLI_UTILEXECUTORFACTORY_H
