#ifndef HW01_CLI_COMMANDNAMEHASH_H
#define HW01_CLI_COMMANDNAMEHASH_H

#include <unordered_map>
#include <string>
#include <CommandName.h>

class CommandNameHash {
public:
    size_t operator()(const CommandName &commandName) const;
};


#endif //HW01_CLI_COMMANDNAMEHASH_H
