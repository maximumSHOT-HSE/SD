#ifndef HW01_CLI_PIPETOKENIZER_H
#define HW01_CLI_PIPETOKENIZER_H

#include "ITokenizer.h"

class PipeTokenizer final : public ITokenizer {
public:
    PipeTokenizer(const std::unordered_set<char> &quotes) : ITokenizer(quotes) {}

    static bool isPipe(char symbol) {
        return symbol == '|';
    }

public:
    std::vector<std::string> tokenize(const std::string &s) override;
};

#endif //HW01_CLI_PIPETOKENIZER_H

