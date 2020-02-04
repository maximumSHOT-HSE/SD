#include <Environment.h>

const ICommandExecutor &Environment::getCommandExecutorByCommandName(const CommandName &commandName) const {
    const auto &executor = factory.getCommandExecutorByCommandName(commandName);
    if (executor.has_value()) {
        return *executor.value();
    } else {
        return *externalExecutor;
    }
}

Environment::Environment()
        : factory(),
          echoExecutor(new EchoExecutor()),
          exitExecutor(new ExitExecutor()),
          catExecutor(new CatExecutor()),
          pwdExecutor(new PWDExecutor()),
          wcExecutor(new WCExecutor()),
          externalExecutor(new ExternalExecutor()) {
    factory.registerExecutor(CommandName("echo"), echoExecutor);
    factory.registerExecutor(CommandName("exit"), exitExecutor);
    factory.registerExecutor(CommandName("cat"), catExecutor);
    factory.registerExecutor(CommandName("pwd"), pwdExecutor);
    factory.registerExecutor(CommandName("wc"), wcExecutor);
}

void Environment::setVariableValue(const std::string &variableName, const std::string &variableValue) {
    variableNameToValue[variableName] = variableValue;
}

const std::string &Environment::getVariableValue(const std::string &variableName) {
    return variableNameToValue[variableName];
}
