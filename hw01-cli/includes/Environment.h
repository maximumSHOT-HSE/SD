#ifndef HW01_CLI_ENVIRONMENT_H
#define HW01_CLI_ENVIRONMENT_H

#include <commands/CommandExecutorFactory.h>
#include <commands/Command.h>
#include <commands/CommandName.h>
#include <executors/EchoExecutor.h>
#include <unordered_map>
#include <string>
#include <executors/ExitExecutor.h>

class Environment {
public:
    Environment();

    const ICommandExecutor &getCommandExecutorByCommandName(
            const CommandName &commandName
    ) const;

    const std::string &getVariableValue(const std::string &variableName);

    void setVariableValue(const std::string &variableName, const std::string &variableValue);

private:
    CommandExecutorFactory factory;
    std::unordered_map<std::string, std::string> variableNameToValue;

    EchoExecutor *echoExecutor;
    ExitExecutor *exitExecutor;
};

#endif //HW01_CLI_ENVIRONMENT_H
