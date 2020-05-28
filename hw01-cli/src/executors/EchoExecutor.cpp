#include "executors/EchoExecutor.h"

Status EchoExecutor::execute(
        const Command &command,
        StringChannel &inputChannel,
        StringChannel &outputChannel
) const {

    const auto &arguments = command.getCommandArguments().stripe().asTokensVector();

    std::vector<char> quotesStack;

    for (size_t i = 0; i < arguments.size(); i++) {
        if (quotesStack.empty() && arguments[i].getTokenType() == TokenType::SPACE
            && (i == 0u || arguments[i - 1].getTokenType() == TokenType::SPACE)) {
            continue;
        }
        if (arguments[i].getTokenType() == TokenType::QUOTE) {
            if (!quotesStack.empty() && quotesStack.front() != arguments[i].asString().front()) {
                outputChannel.write(arguments[i].asString());
            }
            if (quotesStack.empty() || quotesStack.front() != arguments[i].asString().front()) {
                quotesStack.push_back(arguments[i].asString().front());
            } else {
                quotesStack.clear();
            }
        } else {
            outputChannel.write(arguments[i].asString());
        }
    }
    outputChannel.write("\n");

    return Status();
}
