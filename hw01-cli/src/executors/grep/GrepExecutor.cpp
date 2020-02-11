#include <executors/grep/GrepExecutor.h>
#include <executors/grep/GrepArguments.h>
#include <fstream>
#include <regex>
#include <iostream>

Status GrepExecutor::execute(
        const Command &command,
        StringChannel &inputChannel,
        StringChannel &outputChannel
) const {
    GrepArguments arguments = GrepArguments(command);

    if (!arguments.getFiles().empty()) {
        inputChannel.clear();
        for (const std::string &fileName : arguments.getFiles()) {
            inputChannel.writeFile(fileName);
        }
    }

    return executeFromChannelMode(inputChannel, outputChannel, arguments);
}

Status GrepExecutor::executeFromChannelMode(
        StringChannel &inputChannel,
        StringChannel &outputChannel,
        const GrepArguments &arguments
) const {

    std::regex regex(arguments.getRegexp(), std::regex_constants::grep);
    if (arguments.isCaseSensitivity()) {
        regex.assign(
                arguments.getRegexp(),
                std::regex_constants::grep | std::regex_constants::icase
        );
    }

    while (!inputChannel.empty()) {
        const std::string line = inputChannel.readLine();
        if (std::regex_search(line, regex)) {
            outputChannel.write(line);
        }
    }

    std::cout << std::endl;

    return Status();
}

