#ifndef HW01_CLI_COMMANDBUILDER_H
#define HW01_CLI_COMMANDBUILDER_H

#include <Token.h>
#include <Command.h>

class CommandBuilder {
public:
    void appendToken(const Token &token);

    void clear();

    Command buildCommand();
};


#endif //HW01_CLI_COMMANDBUILDER_H
