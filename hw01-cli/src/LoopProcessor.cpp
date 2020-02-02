#include <LoopProcessor.h>
#include <CommandBuilder.h>
#include <ICommandExecutor.h>
#include <ITokenizer.h>
#include <LinearTokenizer.h>
#include <sstream>
#include <StringChannel.h>

Response LoopProcessor::process(
        const std::string &s,
        const Environment &environment
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
            Command command = commandBuilder.buildCommand();
            commandBuilder.clear();
            // TODO: substitution
            Status status = environment
                    .getCommandExecutorByCommandName(command.getCommandName())
                    .execute(command.getCommandArguments(), inputChannel, outputChannel);
            // TODO: add exit command
            lastCommandStatus = status;

            std::swap(inputChannel, outputChannel);
            outputChannel.clear();
        } else {
            commandBuilder.appendToken(token);
        }
    }

    return Response(lastCommandStatus, inputChannel);
}

LoopProcessor::~LoopProcessor() {
    delete tokenizer;
}

LoopProcessor::LoopProcessor() : tokenizer(new LinearTokenizer()) {}
