#ifndef HW01_CLI_UTILEXECUTORFACTORY_H
#define HW01_CLI_UTILEXECUTORFACTORY_H

#include "executors/ICommandExecutor.h"
#include "commands/CommandName.h"

#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <optional>
#include <memory>

/// Entity for registering and giving commands by its name. All commands to be registered should implement
/// ICommandExecutor interface.
class CommandExecutorFactory {
public:
    /// Adds given command executor with given name to the list of registered command. If there are several commands
    /// with the same name then get method may returns any of them.
    void registerExecutor(
            const CommandName &commandName,
            std::shared_ptr<ICommandExecutor> commandExecutor
    );

    /// Gives an instance of command executor by given name. If there is no command executor with given name then
    /// std::optional without value will be returned.
    std::optional<std::shared_ptr<ICommandExecutor>> getCommandExecutorByCommandName(
            const CommandName &commandName
    ) const;

private:
    std::vector<std::pair<CommandName, std::shared_ptr<ICommandExecutor>>> nameToExecutorMap;
};

#endif //HW01_CLI_UTILEXECUTORFACTORY_H
