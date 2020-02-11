#include "executors/GrepExecutor.h"

#include <cxxopts.hpp>

Status GrepExecutor::execute(
        const Command &command, StringChannel &inputChannel,
        StringChannel &outputChannel
) const {
    cxxopts::Options options("grep", "Prints lines matching a pattern");

    options.add_options()
            ("i", "Case sensitivity")
            ("w", "Search only whole words")
            (
                    "n",
                    "Print n lines after matched line",
                    cxxopts::value<unsigned int>()
            )
            (
                    "regexp",
                    "Regular expression to be used for search matchings",
                    cxxopts::value<std::string>()
            )
            (
                    "files",
                    "File to be processed by grep",
                    cxxopts::value<std::vector<std::string>>()
            );

    std::cout << command.getCommandArguments().asString() << " !!!\n";

    options.parse_positional({"regexp", "files"});

    const auto &tokens = command.getCommandArguments().asTokensVector();
    char **args = new char*[tokens.size() + 1];
    int argc = 0;
    {
        char *_name = new char[10]();
        _name[0] = 'g';
        args[argc++] = _name;
    }
    for (const auto &token : tokens) {
        if (token.getTokenType() != TokenType::LITERAL) {
            continue;
        }
        const std::string &stringArg = token.asString();
        char *arg = new char[stringArg.size() + 1]();
        memcpy(arg, stringArg.c_str(), stringArg.size());
        args[argc++] = arg;
    }

    auto result = options.parse(argc, args);

    std::cout << "\n----------\n";

    std::cout << "i = " << result.count("i") << " !!!\n";
    if (result.count("n"))
        std::cout << "n = " << result["n"].as<unsigned int>() << "\n";
    if (result.count("regexp"))
        std::cout << "regexp = " << result["regexp"].as<std::string>() << "\n";
    if (result.count("files")) {
        std::cout << "files = { ";
        auto files = result["files"].as<std::vector<std::string>>();
        for (auto x : files)
            std::cout << x << " ";
        std::cout << "}\n";
    }

    for (int i = 0; i < argc; i++) {
        delete[] args[i];
    }
    delete[] args;

    return Status();
}
