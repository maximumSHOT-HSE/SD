#ifndef HW01_CLI_UTILEXECUTORFACTORY_H
#define HW01_CLI_UTILEXECUTORFACTORY_H

#include <string>
#include <executors/ICommandExecutor.h>
#include <commands/CommandName.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <optional>

class CommandExecutorFactory {
public:
    void registerExecutor(
            const CommandName &commandName,
            ICommandExecutor *commandExecutor
    );

    std::optional<ICommandExecutor *const> getCommandExecutorByCommandName(
            const CommandName &commandName
    ) const;

private:
    std::vector<std::pair<CommandName, ICommandExecutor *const >> nameToExecutorMap;
};

#endif //HW01_CLI_UTILEXECUTORFACTORY_H
