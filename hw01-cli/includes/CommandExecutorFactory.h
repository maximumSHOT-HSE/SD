#ifndef HW01_CLI_UTILEXECUTORFACTORY_H
#define HW01_CLI_UTILEXECUTORFACTORY_H

#include <string>
#include <ICommandExecutor.h>
#include <CommandName.h>
#include <unordered_map>

class CommandExecutorFactory {
private:
    void registerExecutor(
            const CommandName &commandName,
            const ICommandExecutor &commandExecutor
    );

    const ICommandExecutor &getCommandExecutorByCommandName(
            const CommandName &commandName
    ) const;

private:
    std::unordered_map<CommandName, ICommandExecutor> nameToExecutorMap;
};

#endif //HW01_CLI_UTILEXECUTORFACTORY_H
