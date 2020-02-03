#ifndef HW01_CLI_SHELL_H
#define HW01_CLI_SHELL_H

#include <tokenizers/ITokenizer.h>
#include <processors/IProcessor.h>
#include <Environment.h>

class Shell {
public:
    void run();

    Shell();

    ~Shell();

private:
    IProcessor *processor;
    Environment *environment;
};


#endif //HW01_CLI_SHELL_H
