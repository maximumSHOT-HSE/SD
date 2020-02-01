#include <Environment.h>


const CommandExecutor &Environment::getCommandExecutorByCommandName(const CommandName &commandName) const {
    return factory.getCommandExecutorByCommandName(commandName);
}

void Environment::registerExecutor(const CommandName &commandName, const CommandExecutor &commandExecutor) {
    factory.registerExecutor(commandName, commandExecutor);
}

