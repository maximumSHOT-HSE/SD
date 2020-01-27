#include "PipeTokenizer.h"
#include <optional>


std::vector<std::string> PipeTokenizer::tokenize(const std::string &s) {
    size_t n = s.size();
    std::vector<std::string> tokens;
    std::string buffer;
    std::optional<char> lastQuote;

    for (size_t i = 0u; i < n; i++) {
        if (isPipe(s[i])) {
            if (lastQuote.has_value()) {
                buffer.push_back(s[i]);
            } else {
                tokens.push_back(buffer);
                buffer.clear();
            }
        } else {
            buffer.push_back(s[i]);
            if (isQuote(s[i])) {
                if (!lastQuote.has_value()) {
                    lastQuote = s[i];
                } else if (lastQuote.value() == s[i]) {
                    lastQuote.reset();
                }
            }
        }
    }

    tokens.push_back(buffer);

    return tokens;
}
