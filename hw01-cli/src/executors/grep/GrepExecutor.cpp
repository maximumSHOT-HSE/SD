#include <executors/grep/GrepExecutor.h>
#include <executors/grep/GrepArguments.h>
#include <fstream>

#include <iostream>

Status GrepExecutor::execute(
        const Command &command,
        StringChannel &inputChannel,
        StringChannel &outputChannel
) const {
    GrepArguments arguments = GrepArguments(command);

    if (arguments.getFiles().empty()) {
        inputChannel.clear();
        for (const std::string &fileName : arguments.getFiles()) {
            inputChannel.writeFile(fileName);
        }
    }

    return executeFromChannelMode(inputChannel, arguments);
}

Status GrepExecutor::executeFromChannelMode(
        StringChannel &inputChannel,
        const GrepArguments &arguments
) const {

    std::cout << arguments.getRegexp() << " = r\n";

    return Status();
}

