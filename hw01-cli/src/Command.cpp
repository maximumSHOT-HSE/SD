#include "Command.h"

const CommandName &Command::getCommandName() const {
    return commandName;
}

const CommandArguments &Command::getCommandArguments() const {
    return commandArguments;
}
