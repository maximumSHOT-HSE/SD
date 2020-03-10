#include "processors/LoopProcessor.h"
#include "commands/CommandBuilder.h"
#include "tokenizers/LinearTokenizer.h"
#include "Substitutor.h"

#include <iostream>

Response LoopProcessor::process(
        const std::string &s,
        Environment &environment,
        const CommandExecutorFactory &factory
) {
    tokenizer->clear();
    tokenizer->append(s);

    CommandBuilder commandBuilder;
    Status lastCommandStatus;
    StringChannel inputChannel, outputChannel;

    for (; lastCommandStatus.isSuccess() && tokenizer->hasNextToken();) {

        Token token = tokenizer->nextToken();
        TokenType tokenType = token.getTokenType();

        if (tokenType == TokenType::PIPE || tokenType == TokenType::END) {
            std::string commandString = commandBuilder.buildCommandString();
            commandBuilder.clear();
            for (shortTermTokenizer->clear(), shortTermTokenizer->append(commandString);
                 shortTermTokenizer->hasNextToken();) {
                commandBuilder.appendToken(shortTermTokenizer->nextToken());
            }
            Command command = commandBuilder.buildCommand();
            commandBuilder.clear();
            Status status;

            if (!Substitutor::tryAssign(command, environment)) {
                try {
                    const auto &executor = factory.getCommandExecutorByCommandName(command.getCommandName());
                    status = executor.value().get()->execute(command, inputChannel, outputChannel);
                } catch (const std::exception &e) {
                    status.setExitCode(-1);
                    status.setMessage("Error: " + std::string(e.what()));
                }
            }

            lastCommandStatus = status;
            environment.setLastCommandExitCode(lastCommandStatus.getExitCode());

            std::swap(inputChannel, outputChannel);
            outputChannel.clear();
        } else {
            commandBuilder.appendToken(
                    LoopProcessor::removeOuterQuotes(
                            Substitutor::substitute(token, environment)
                    )
            );
        }
    }

    if (!lastCommandStatus.isSuccess()) {
        inputChannel.write(lastCommandStatus.getMessage());
    }

    return Response(lastCommandStatus, inputChannel);
}

LoopProcessor::~LoopProcessor() {
}

LoopProcessor::LoopProcessor()
        : tokenizer(new LinearTokenizer()),
          shortTermTokenizer(new LinearTokenizer()) {}

Token LoopProcessor::removeOuterQuotes(const Token &token) {
    std::optional<char> lastQuote;
    std::string content;
    for (char c : token.asString()) {
        if (c == '\'' || c == '"') {
            if (lastQuote.has_value()) {
                if (lastQuote.value() == c) {
                    lastQuote.reset();
                } else {
                    content.push_back(c);
                }
            } else {
                lastQuote = c;
            }
        } else {
            content.push_back(c);
        }
    }
    return Token(token.getTokenType(), content);
}
