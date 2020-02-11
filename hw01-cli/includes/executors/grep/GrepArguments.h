#ifndef HW01_CLI_ARGV_H
#define HW01_CLI_ARGV_H

#include <commands/Command.h>

class GrepArguments {
public:
    explicit GrepArguments(const Command &command);

    int &getArgc();

    char **&getArgv();

    ~GrepArguments();

    bool isCaseSensitivity() const;

    bool isSearchOnlyWords() const;

    unsigned int getLinesNumberToPrint() const;

    const std::string &getRegexp() const;

    const std::vector<std::string> &getFiles() const;

private:
    int argc;
    char **argv;

    bool caseSensitivity;
    bool searchOnlyWords;
    unsigned int nLinesToPrint;
    std::string regexp;
    std::vector<std::string> files;
};


#endif //HW01_CLI_ARGV_H
