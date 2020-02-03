#include <commands/CommandExecutorFactory.h>

#include <tuple>
#include <vector>

void CommandExecutorFactory::registerExecutor(
        const CommandName &commandName,
        ICommandExecutor *const commandExecutor) {
    nameToExecutorMap.emplace_back(commandName, commandExecutor);
}

const ICommandExecutor &CommandExecutorFactory::getCommandExecutorByCommandName(
        const CommandName &commandName
) const {
    for (const auto &item : nameToExecutorMap) {
        if (item.first == commandName) {
            return *item.second;
        }
    }
    // TODO: add exception
}
