#ifndef HW01_CLI_COMMANDNAME_H
#define HW01_CLI_COMMANDNAME_H

#include <string>

class CommandName {
public:
    CommandName() = default;

    CommandName(const std::string name);

    const std::string &getName() const;

private:
    std::string name;
};


#endif //HW01_CLI_COMMANDNAME_H
