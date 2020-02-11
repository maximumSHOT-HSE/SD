#ifndef HW01_CLI_ARGV_H
#define HW01_CLI_ARGV_H

#include <commands/Command.h>

class GrepArguments {
public:
    explicit GrepArguments(const Command &command);

    int &getArgc();

    char **&getArgv();

    ~GrepArguments();

private:
    int argc;
    char **argv;
};


#endif //HW01_CLI_ARGV_H
