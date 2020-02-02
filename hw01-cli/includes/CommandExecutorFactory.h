#ifndef HW01_CLI_UTILEXECUTORFACTORY_H
#define HW01_CLI_UTILEXECUTORFACTORY_H

#include <string>
#include <ICommandExecutor.h>
#include <CommandName.h>
#include <unordered_map>
#include <CommandNameHash.h>
#include <map>
#include <vector>

class CommandExecutorFactory {
public:
    void registerExecutor(
            const CommandName &commandName,
            ICommandExecutor *const commandExecutor
    );

    const ICommandExecutor &getCommandExecutorByCommandName(
            const CommandName &commandName
    ) const;

private:
    std::vector<std::pair<CommandName, ICommandExecutor *const >> nameToExecutorMap;
};

#endif //HW01_CLI_UTILEXECUTORFACTORY_H
