#include "tokenizers/LinearTokenizer.h"

#include <cctype>
#include <optional>

Token LinearTokenizer::nextToken() {
    if (pointer == (int) s.size()) {
        pointer++;
        return Token(TokenType::END);
    }
    if (std::isspace(s[pointer])) { // is space?
        pointer++;
        return Token(TokenType::SPACE, " ");
    }
    if (auto foundToken = specialSymbols.find(s[pointer]); foundToken != specialSymbols.end()) { // special symbols
        pointer++;
        return foundToken->second;
    }
    if (s[pointer] == '\"' || s[pointer] == '\'') {
        return Token(TokenType::QUOTE, std::string(1, s[pointer++]));
    }
    std::string tokenContent;
    for (int &i = pointer; i < (int) s.size(); i++) {
        if (std::isspace(s[i]) || specialSymbols.count(s[i]) || s[i] == '\"' || s[i] == '\'') {
            break;
        }
        tokenContent.push_back(s[i]);
    }
    return Token(TokenType::LITERAL, tokenContent);
}

bool LinearTokenizer::hasNextToken() {
    return pointer <= (int) s.size();
}

void LinearTokenizer::append(const std::string &s) {
    this->s += s;
}

void LinearTokenizer::clear() {
    s.clear();
    pointer = 0;
}
