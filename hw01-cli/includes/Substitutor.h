#ifndef HW01_CLI_SUBSTITUTOR_H
#define HW01_CLI_SUBSTITUTOR_H

#include <string>
#include <Token.h>
#include <Environment.h>
#include <vector>
#include <tokenizers/ITokenizer.h>

class Substitutor {
public:
    static Token substitute(const Token &token, Environment &environment);

    static bool tryAssign(const Command &command, Environment &environment);

private:
    static std::string substitute(const std::vector<Token> &tokens, Environment &environment);

    static bool isSibstitution(
            const Token &dollarToken,
            const Token &variableNameToken
    );

    static bool isValidVariableName(const std::string &name);

    static bool isTokenAvailableForSubstitution(const Token &token);
};


#endif //HW01_CLI_SUBSTITUTOR_H
