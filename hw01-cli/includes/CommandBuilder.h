#ifndef HW01_CLI_COMMANDBUILDER_H
#define HW01_CLI_COMMANDBUILDER_H

#include <Token.h>
#include <Command.h>
#include <vector>

class CommandBuilder {
public:
    void appendToken(const Token &token);

    void clear();

    Command buildCommand() const;

    std::string buildCommandString() const;

private:
    std::vector<Token> parts;
};


#endif //HW01_CLI_COMMANDBUILDER_H
