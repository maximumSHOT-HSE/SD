#include <CommandExecutorFactory.h>

void CommandExecutorFactory::registerExecutor(
        const CommandName &commandName,
        const CommandExecutor &commandExecutor) {
    nameToExecutorMap[commandName] = commandExecutor;
}

const CommandExecutor &CommandExecutorFactory::getCommandExecutorByCommandName(
        const CommandName &commandName
) const {
    return nameToExecutorMap[commandName];
}
