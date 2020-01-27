#ifndef HW01_CLI_ITOKENIZER_H
#define HW01_CLI_ITOKENIZER_H

#include <vector>
#include <string>
#include <unordered_set>

class ITokenizer {
public:
    virtual std::vector<std::string> tokenize(const std::string& s) = 0;

    ITokenizer(const std::unordered_set<char>& quotes): quotes(quotes) { }
protected:
    virtual bool isQuote(char c) {
        return quotes.count(c);
    }
private:
    ITokenizer() = delete;
private:
    std::unordered_set<char> quotes;
};

#endif //HW01_CLI_ITOKENIZER_H
