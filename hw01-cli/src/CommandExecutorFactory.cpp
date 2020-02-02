#include <CommandExecutorFactory.h>

void CommandExecutorFactory::registerExecutor(
        const CommandName &commandName,
        const ICommandExecutor &commandExecutor) {
    nameToExecutorMap[commandName] = commandExecutor;
}

const ICommandExecutor &CommandExecutorFactory::getCommandExecutorByCommandName(
        const CommandName &commandName
) const {
    return nameToExecutorMap[commandName];
}
