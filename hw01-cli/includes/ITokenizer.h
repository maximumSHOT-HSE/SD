#ifndef HW01_CLI_ITOKENIZER_H
#define HW01_CLI_ITOKENIZER_H

#include <Token.h>

class ITokenizer {
public:
    virtual Token nextToken() = 0;

    virtual bool hasNextToken() = 0;

    virtual ~ITokenizer() = default;
};

#endif //HW01_CLI_ITOKENIZER_H
