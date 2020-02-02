#include <Substitutor.h>
#include <cctype>
#include <LinearTokenizer.h>


bool Substitutor::isValidVariableNameToken(const Token &nameToken) {
    if (nameToken.getTokenType() != TokenType::LITERAL) {
        return false;
    }
    const auto &name = nameToken.asString();
    if (name.empty()) {
        return false;
    }
    if (!std::isalpha(name.front())) {
        return false;
    }
    for (size_t i = 1; i < name.size(); i++) {
        if (!(std::isalpha(name[i]) || std::isdigit(name[i]))) {
            return false;
        }
    }
    return true;
}

bool Substitutor::isValidVariableValueToken(const Token &valueToken) {
    return !(valueToken.getTokenType() != TokenType::LITERAL);
}

bool Substitutor::isSibstitution(const Token &dollarToken, const Token &variableNameToken) {
    return dollarToken.getTokenType() == TokenType::DOLLAR && isValidVariableNameToken(variableNameToken);
}

std::string Substitutor::substitute(const std::vector<Token> &tokens, Environment &environment) {
    std::string substitution;
    for (size_t i = 0; i < tokens.size(); ) {
        if (i + 1 < tokens.size() && Substitutor::isSibstitution(tokens[i], tokens[i + 1])) {
            substitution += environment.getVariableValue(tokens[i + 1].asString());
            i += 2;
        } else {
            substitution += tokens[i].asString();
            i++;
        }
    }
    return substitution;
}

bool Substitutor::isTokenAvailableForSubstitution(const Token &token) {
    if (token.getTokenType() != TokenType::LITERAL) {
        return false;
    }
    const auto &stringToken = token.asString();
    return stringToken.size() > 1u && stringToken.front() == '"' && stringToken.back() == '"';
}

#include <iostream>

Token Substitutor::substitute(const Token &token, Environment &environment) {
    std::string s = token.asString();
    s = std::string(s.begin() + 1, s.end() - 1);
    LinearTokenizer tokenizer;
    tokenizer.append(s);
    std::vector<Token> tokens;
    while (tokenizer.hasNextToken()) {
        tokens.push_back(tokenizer.nextToken());
    }
    return Token(token.getTokenType(), "\"" + Substitutor::substitute(tokens, environment) + "\"");
}
