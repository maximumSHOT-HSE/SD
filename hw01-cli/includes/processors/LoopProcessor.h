#ifndef HW01_CLI_LOOPPROCESSOR_H
#define HW01_CLI_LOOPPROCESSOR_H

#include <processors/IProcessor.h>

class LoopProcessor : public IProcessor {
public:
    LoopProcessor();

    Response process(
            const std::string &s,
            Environment &environment
    ) override;

    ~LoopProcessor() override;

private:
    static Token removeOuterQuotes(const Token& token);
private:
    ITokenizer *tokenizer;
    ITokenizer *shortTermTokenizer;
};


#endif //HW01_CLI_LOOPPROCESSOR_H
