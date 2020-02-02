#ifndef HW01_CLI_COMMANDARGUMENTS_H
#define HW01_CLI_COMMANDARGUMENTS_H

#include <string>
#include <vector>

class CommandArguments {
public:
    CommandArguments() = default;

    CommandArguments(const std::vector<std::string> &stringArguments);

    std::vector<std::string> asStringsVector() const;

private:
    std::vector<std::string> arguments;
};


#endif //HW01_CLI_COMMANDARGUMENTS_H
