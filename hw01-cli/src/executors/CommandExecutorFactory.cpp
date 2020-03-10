#include "commands/CommandExecutorFactory.h"

void CommandExecutorFactory::registerExecutor(
        const CommandName &commandName,
        std::shared_ptr<ICommandExecutor> commandExecutor) {
    nameToExecutorMap.emplace_back(commandName, commandExecutor);
}

std::optional<std::shared_ptr<ICommandExecutor>> CommandExecutorFactory::getCommandExecutorByCommandName(
        const CommandName &commandName
) const {
    for (const auto &item : nameToExecutorMap) {
        if (item.first == commandName) {
            return std::optional(item.second);
        }
    }
    return std::optional<std::unique_ptr<ICommandExecutor>>();
}
