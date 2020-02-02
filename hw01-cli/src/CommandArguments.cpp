
#include <CommandArguments.h>

#include "CommandArguments.h"

std::vector<std::string> CommandArguments::asStringsVector() const {
    return arguments;
}

CommandArguments::CommandArguments(const std::vector<std::string> &arguments)
        : arguments(arguments) {}
