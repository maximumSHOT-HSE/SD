
#include <CommandName.h>

const std::string &CommandName::getName() const {
    return name;
}

CommandName::CommandName(const std::string name) : name(name) {}
