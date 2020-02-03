#include <Environment.h>

const ICommandExecutor &Environment::getCommandExecutorByCommandName(const CommandName &commandName) const {
    return factory.getCommandExecutorByCommandName(commandName);
}

Environment::Environment()
        : factory(),
          echoExecutor(new EchoExecutor()),
          exitExecutor(new ExitExecutor()),
          catExecutor(new CatExecutor()),
          pwdExecutor(new PWDExecutor()),
          wcExecutor(new WCExecutor()) {
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
