#ifndef HW01_CLI_SHELL_H
#define HW01_CLI_SHELL_H

#include "tokenizers/ITokenizer.h"
#include "processors/IProcessor.h"
#include "Environment.h"
#include "commands/CommandExecutorFactory.h"

#include <memory>

class Shell {
public:
    int run();

    Shell();

private:
    std::unique_ptr<IProcessor> processor;
    std::unique_ptr<Environment> environment;
    std::unique_ptr<CommandExecutorFactory> factory;

    std::shared_ptr<EchoExecutor> echoExecutor;
    std::shared_ptr<ExitExecutor> exitExecutor;
    std::shared_ptr<CatExecutor> catExecutor;
    std::shared_ptr<PWDExecutor> pwdExecutor;
    std::shared_ptr<WCExecutor> wcExecutor;
    std::shared_ptr<ExternalExecutor> externalExecutor;
    std::shared_ptr<EmptyExecutor> emptyExecutor;
};


#endif //HW01_CLI_SHELL_H
