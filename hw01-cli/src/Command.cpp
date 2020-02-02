#include "Command.h"

const CommandName &Command::getCommandName() const {
    return commandName;
}

const CommandArguments &Command::getCommandArguments() const {
    return commandArguments;
}

Command::Command(
        const CommandName &commandName,
        const CommandArguments &commandArguments
) : commandName(commandName), commandArguments(commandArguments) {}
