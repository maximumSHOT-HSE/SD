#include <Environment.h>

const ICommandExecutor &Environment::getCommandExecutorByCommandName(const CommandName &commandName) const {
    return factory.getCommandExecutorByCommandName(commandName);
}

Environment::Environment()
        : factory(), echoExecutor(new EchoExecutor()) {
    factory.registerExecutor(CommandName("echo"), echoExecutor);
}
