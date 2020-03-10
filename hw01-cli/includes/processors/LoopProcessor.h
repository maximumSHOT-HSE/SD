#ifndef HW01_CLI_LOOPPROCESSOR_H
#define HW01_CLI_LOOPPROCESSOR_H

#include "processors/IProcessor.h"
#include "commands/CommandExecutorFactory.h"

class LoopProcessor : public IProcessor {
public:
    LoopProcessor();

    Response process(
            const std::string &s,
            Environment &environment,
            const CommandExecutorFactory &factory
    ) override;

    ~LoopProcessor() override;

private:
    static Token removeOuterQuotes(const Token& token);
private:
    ITokenizer *tokenizer;
    ITokenizer *shortTermTokenizer;
};


#endif //HW01_CLI_LOOPPROCESSOR_H
