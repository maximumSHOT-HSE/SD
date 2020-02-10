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
                    "A", "Print n lines after matched line",
                    cxxopts::value<unsigned int>()
            )
            (
                    "regexp", "Regular expression to be used for search matchings",
                    cxxopts::value<std::string>()
            )
            (
                    "files", "File to be processed by grep",
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

    for (auto x : result.arguments()) {
        std::cout << x.value() << "|" << x.key() << "\n";
    }

    std::cout << "\n----------\n";

    std::cout << result.count("i") << " !!!\n";

    for (int i = 0; i < argc; i++) {
        delete[] args[i];
    }
    delete[] args;

    return Status();
}
