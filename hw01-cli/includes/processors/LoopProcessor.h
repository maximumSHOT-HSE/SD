#ifndef HW01_CLI_LOOPPROCESSOR_H
#define HW01_CLI_LOOPPROCESSOR_H

#include "processors/IProcessor.h"
#include "commands/CommandExecutorFactory.h"

#include <memory>

class LoopProcessor : public IProcessor {
public:
    LoopProcessor();

    Response process(
            const std::string &s,
            Environment &environment,
            const CommandExecutorFactory &factory
    ) override;

private:
    std::unique_ptr<ITokenizer> tokenizer;
    std::unique_ptr<ITokenizer> shortTermTokenizer;
};


#endif //HW01_CLI_LOOPPROCESSOR_H
