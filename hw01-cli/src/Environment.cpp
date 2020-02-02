#include <Environment.h>

const ICommandExecutor &Environment::getCommandExecutorByCommandName(const CommandName &commandName) const {
    return factory.getCommandExecutorByCommandName(commandName);
}

void Environment::registerExecutor(const CommandName &commandName, const ICommandExecutor &commandExecutor) {
    factory.registerExecutor(commandName, commandExecutor);
}
