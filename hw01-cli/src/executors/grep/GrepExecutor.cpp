#include <executors/grep/GrepExecutor.h>

#include <cxxopts.hpp>
#include <executors/grep/GrepArguments.h>

Status GrepExecutor::execute(
        const Command &command, StringChannel &inputChannel,
        StringChannel &outputChannel
) const {
    const std::string CASE_SENSITIVITY_KEY = "i";
    const std::string SEARCH_ONLY_WORDS_KEY = "w";
    const std::string PRINT_N_LINES_KEY = "n";
    const std::string REGEXP_KEY = "regexp";
    const std::string FILES_KEY = "files";

    cxxopts::Options options("grep", "Prints lines matching a pattern");
    options.add_options()
            (CASE_SENSITIVITY_KEY, "Case sensitivity")
            (SEARCH_ONLY_WORDS_KEY, "Search only whole words")
            (
                    PRINT_N_LINES_KEY,
                    "Print n lines after matched line",
                    cxxopts::value<unsigned int>()->default_value("0")
            )
            (
                    REGEXP_KEY,
                    "Regular expression to be used for search matchings",
                    cxxopts::value<std::string>()->default_value("")
            )
            (
                    FILES_KEY,
                    "File to be processed by grep",
                    cxxopts::value<std::vector<std::string>>()->default_value({})
            );
    options.parse_positional({REGEXP_KEY, FILES_KEY});
    GrepArguments grepArguments(command);
    auto result = options.parse(grepArguments.getArgc(), grepArguments.getArgv());

    bool caseSensitivity = result[CASE_SENSITIVITY_KEY].as<bool>();
    bool searchOnlyWords = result[SEARCH_ONLY_WORDS_KEY].as<bool>();
    unsigned int nLinesToPrint = result[PRINT_N_LINES_KEY].as<unsigned int>();
    std::string regexp = result[REGEXP_KEY].as<std::string>();
    std::vector<std::string> files = result[FILES_KEY].as<std::vector<std::string>>();



    return Status();
}
