#ifndef HW01_CLI_SHELL_H
#define HW01_CLI_SHELL_H

#include "tokenizers/ITokenizer.h"
#include "processors/IProcessor.h"
#include "Environment.h"

#include <memory>

class Shell {
public:
    int run();

    Shell();

private:
    std::unique_ptr<IProcessor> processor;
    std::unique_ptr<Environment> environment;
};


#endif //HW01_CLI_SHELL_H
