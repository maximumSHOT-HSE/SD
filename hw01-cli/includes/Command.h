#ifndef HW01_CLI_COMMAND_H
#define HW01_CLI_COMMAND_H

#include <CommandName.h>
#include <CommandArguments.h>

class Command {
public:
    const CommandName &getCommandName() const;

    const CommandArguments &getCommandArguments() const;

private:
    CommandName commandName;
    CommandArguments commandArguments;
};


#endif //HW01_CLI_COMMAND_H
