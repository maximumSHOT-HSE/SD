#ifndef HW01_CLI_ENVIRONMENT_H
#define HW01_CLI_ENVIRONMENT_H

#include "commands/CommandExecutorFactory.h"
#include "commands/Command.h"
#include "commands/CommandName.h"

#include "executors/EchoExecutor.h"
#include "executors/ExitExecutor.h"
#include "executors/CatExecutor.h"
#include "executors/PWDExecutor.h"
#include "executors/WCExecutor.h"
#include "executors/ExternalExecutor.h"
#include "executors/EmptyExecutor.h"

#include <unordered_map>
#include <string>

/// Entity for environment which stores env variables and builtin commands inside and can work with it
class Environment {
public:
    Environment();

    const ICommandExecutor &getCommandExecutorByCommandName(
            const CommandName &commandName
    ) const;

    const std::string &getVariableValue(const std::string &variableName);

    void setVariableValue(const std::string &variableName, const std::string &variableValue);

    int getLastCommandExitCode() const;

    void setLastCommandExitCode(int lastCommandExitCode);

private:
    CommandExecutorFactory factory;
    std::unordered_map<std::string, std::string> variableNameToValue;

    int lastCommandExitCode = 0;

    EchoExecutor *echoExecutor;
    ExitExecutor *exitExecutor;
    CatExecutor *catExecutor;
    PWDExecutor *pwdExecutor;
    WCExecutor *wcExecutor;
    ExternalExecutor *externalExecutor;
    EmptyExecutor *emptyExecutor;
};

#endif //HW01_CLI_ENVIRONMENT_H
