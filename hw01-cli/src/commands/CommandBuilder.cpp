#include "commands/CommandBuilder.h"
#include "Substitutor.h"
#include "tokenizers/LinearTokenizer.h"

#include <iostream>
#include <assert.h>
#include <algorithm>
#include <commands/CommandBuilder.h>


void CommandBuilder::appendToken(const Token &token) {
    if (!token.empty()) {
        tokens.push_back(token);
    }
}

void CommandBuilder::clear() {
    tokens.clear();
}

Command CommandBuilder::buildCommand(Environment &environment) {
    this->substitute(environment);
    int start = 0;
    while (start < (int) tokens.size() && tokens[start].getTokenType() == TokenType::SPACE) {
        start++;
    }
    if (start == (int) tokens.size()) {
        return Command();
    }
    return Command(
            CommandName(tokens[start].asString()),
            CommandArguments(std::vector<Token>(tokens.begin() + start + 1, tokens.end()))
    );
}

std::string CommandBuilder::buildCommandString() const {
    std::string commandString;
    for (const auto &token : tokens) {
        commandString += token.asString();
    }
    return commandString;
}

void CommandBuilder::substitute(Environment &environment) {
    std::string totalCommand;
    for (int i = 0; i < (int) tokens.size(); i++) {
        if (i + 1 < (int) tokens.size() && Substitutor::isSibstitution(tokens[i], tokens[i + 1])) {
            std::string helper = "\"" + tokens[i].asString() + tokens[i + 1].asString() + "\"";
            helper = Substitutor::substitute(Token(TokenType::LITERAL, helper), environment).asString();
            totalCommand += helper.substr(1, (int) helper.size() - 2);
            i++;
        } else {
            totalCommand += tokens[i].asString();
        }
    }
    clear();
    LinearTokenizer tokenizer;
    tokenizer.append(totalCommand);
    while (tokenizer.hasNextToken()) {
        appendToken(tokenizer.nextToken());
    }
}
