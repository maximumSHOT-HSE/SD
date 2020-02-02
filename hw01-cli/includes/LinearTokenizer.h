#ifndef HW01_CLI_LINEARTOKENIZER_H
#define HW01_CLI_LINEARTOKENIZER_H

#include <ITokenizer.h>

class LinearTokenizer : public ITokenizer {
public:
    Token nextToken() override;

    bool hasNextToken() override;

    void append(const std::string &s) override;

    void clear() override;

private:
    std::string s = "";
    int pointer = 0;
};


#endif //HW01_CLI_LINEARTOKENIZER_H
