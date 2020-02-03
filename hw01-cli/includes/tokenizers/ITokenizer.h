#ifndef HW01_CLI_ITOKENIZER_H
#define HW01_CLI_ITOKENIZER_H

#include <Token.h>
#include <string>

class ITokenizer {
public:
    virtual void append(const std::string &s) = 0;

    virtual void clear() = 0;

    virtual Token nextToken() = 0;

    virtual bool hasNextToken() = 0;

    virtual ~ITokenizer() = default;
};

#endif //HW01_CLI_ITOKENIZER_H
