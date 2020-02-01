#ifndef HW01_CLI_LINEARTOKENIZER_H
#define HW01_CLI_LINEARTOKENIZER_H

#include <ITokenizer.h>

class LinearTokenizer : public ITokenizer {
public:
    Token nextToken() override;

    bool hasNextToken() override;

    ~LinearTokenizer() override;
};


#endif //HW01_CLI_LINEARTOKENIZER_H
