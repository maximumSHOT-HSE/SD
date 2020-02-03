#include <executors/WCExecutor.h>
#include <fstream>

Status WCExecutor::execute(
        const CommandArguments &commandArguments,
        StringChannel &inputStream,
        StringChannel &outputStream
) const {
    if (commandArguments.countTokensWithType(TokenType::LITERAL) > 0) {
        return executeAtLeastOneArgumentMode(commandArguments, inputStream, outputStream);
    } else {
        return executeNoArgumentsMode(commandArguments, inputStream, outputStream);
    }
}

Status WCExecutor::executeNoArgumentsMode(
        const CommandArguments &commandArguments,
        StringChannel &inputChannel,
        StringChannel &outputChannel
) const {
    int newlinesCount = 0;
    int wordsCount = 0;
    int bytesCount = 0;
    std::string buffer;
    while (!inputChannel.empty()) {
        buffer = inputChannel.read();
        bytesCount += (int) buffer.size();
        for (char c : buffer) {
            if (c == '\n') {
                newlinesCount++;
            }
        }
    }
    outputChannel.write(std::to_string(newlinesCount));
    outputChannel.write(" ");
    outputChannel.write(std::to_string(wordsCount));
    outputChannel.write(" ");
    outputChannel.write(std::to_string(bytesCount));
    outputChannel.write("\n");
    return Status();
}

Status WCExecutor::executeAtLeastOneArgumentMode(
        const CommandArguments &commandArguments,
        StringChannel &inputChannel,
        StringChannel &outputChannel
) const {
    int totalNewlinesCount = 0;
    int totalWordsCount = 0;
    int totalBytesCount = 0;

    for (const auto &token : commandArguments.asTokensVector()) {

        if (token.getTokenType() != TokenType::LITERAL) {
            continue;
        }

        int newlinesCount = 0;
        int wordsCount = 0;
        int bytesCount = 0;

        std::ifstream fin(token.asString()); // TODO: add exceptions
        for (char c; fin.get(c);) {
            bytesCount++;
            if (c == '\n') {
                newlinesCount++;
            }
        }

        outputChannel.write(std::to_string(newlinesCount) + " ");
        outputChannel.write(std::to_string(wordsCount) + " ");
        outputChannel.write(std::to_string(bytesCount) + " ");
        outputChannel.write(token.asString() + "\n");

        totalNewlinesCount += newlinesCount;
        totalWordsCount += wordsCount;
        totalBytesCount += bytesCount;
    }

    outputChannel.write(std::to_string(totalNewlinesCount) + " ");
    outputChannel.write(std::to_string(totalWordsCount) + " ");
    outputChannel.write(std::to_string(totalBytesCount) + " ");
    outputChannel.write("total\n");

    return Status();
}
