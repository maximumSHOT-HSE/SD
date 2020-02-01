#include <LoopProcessor.h>
#include <CommandBuilder.h>
#include <CommandExecutor.h>
#include <ITokenizer.h>
#include <LinearTokenizer.h>
#include <sstream>

Response LoopProcessor::process(
        const std::string &s,
        const Environment &environment
) {
    CommandBuilder commandBuilder;
    Status lastCommandStatus;
    std::stringstream inputStream, outputStream;

    for (; lastCommandStatus.isSuccess() && tokenizer->hasNextToken();
           swap(inputStream, outputStream), outputStream.clear()) {

        Token token = tokenizer->nextToken();
        TokenType tokenType = token.getTokenType();

        if (tokenType == TokenType::PIPE || tokenType == TokenType::END) {
            Command command = commandBuilder.buildCommand();
            commandBuilder.clear();
            // TODO: substitution
            Status status = environment
                    .getCommandExecutorByCommandName(command.getCommandName())
                    .execute(command.getCommandArguments(), inputStream, outputStream);
            // TODO: add exit command
            lastCommandStatus = status;
        } else {
            commandBuilder.appendToken(token);
        }
    }

    std::cout << outputStream.str() << std::endl;

    return Response(lastCommandStatus);
}

LoopProcessor::~LoopProcessor() = default;

LoopProcessor::LoopProcessor() : tokenizer(new LinearTokenizer()) {}
