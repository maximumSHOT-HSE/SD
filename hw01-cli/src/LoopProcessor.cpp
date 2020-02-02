#include <LoopProcessor.h>
#include <CommandBuilder.h>
#include <ICommandExecutor.h>
#include <ITokenizer.h>
#include <LinearTokenizer.h>
#include <sstream>
#include <StringChannel.h>
#include <Substitutor.h>

Response LoopProcessor::process(
        const std::string &s,
        Environment &environment
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
                Token helper = shortTermTokenizer->nextToken();
                if (helper.getTokenType() != TokenType::SPACE) {
                    commandBuilder.appendToken(helper);
                }
            }
            Command command = commandBuilder.buildCommand();
            Status status = environment
                    .getCommandExecutorByCommandName(command.getCommandName())
                    .execute(command.getCommandArguments(), inputChannel, outputChannel);
            // TODO: add exit command
            lastCommandStatus = status;

            std::swap(inputChannel, outputChannel);
            outputChannel.clear();
        } else {
            if (Substitutor::isTokenAvailableForSubstitution(token)) {
                token = Substitutor::substitute(token, environment);
            }
            commandBuilder.appendToken(token);
        }
    }

    return Response(lastCommandStatus, inputChannel);
}

LoopProcessor::~LoopProcessor() {
    delete tokenizer;
}

LoopProcessor::LoopProcessor()
        : tokenizer(new LinearTokenizer()),
          shortTermTokenizer(new LinearTokenizer()) {}
