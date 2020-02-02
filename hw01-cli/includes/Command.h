#ifndef HW01_CLI_COMMAND_H
#define HW01_CLI_COMMAND_H

#include <CommandName.h>
#include <CommandArguments.h>

class Command {
public:
    Command(
            const CommandName &commandName,
            const CommandArguments &commandArguments
    );

    const CommandName &getCommandName() const;

    const CommandArguments &getCommandArguments() const;

private:
    CommandName commandName;
    CommandArguments commandArguments;
};


#endif //HW01_CLI_COMMAND_H
