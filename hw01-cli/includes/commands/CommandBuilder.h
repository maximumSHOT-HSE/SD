#ifndef HW01_CLI_COMMANDBUILDER_H
#define HW01_CLI_COMMANDBUILDER_H

#include <tokenizers/Token.h>
#include <commands/Command.h>
#include <vector>
#include "Environment.h"

class CommandBuilder {
public:
    void appendToken(const Token &token);

    void clear();

    Command buildCommand() const;

    const std::vector<Token> &getTokens() const;

    std::string buildCommandString() const;

private:
    std::vector<Token> tokens;
};


#endif //HW01_CLI_COMMANDBUILDER_H
