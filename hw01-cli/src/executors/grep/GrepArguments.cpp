#include <executors/grep/GrepArguments.h>
#include <cstring>

GrepArguments::GrepArguments(const Command &command) {
    argv = new char *[command.getCommandArguments().size() + 1];

    argv[0] = new char[command.getCommandName().getName().size() + 1]();
    memcpy(
            argv[0],
            command.getCommandName().getName().c_str(),
            command.getCommandName().getName().size()
    );

    argc = 1;
    for (const Token &token : command.getCommandArguments().asTokensVector()) {
        if (token.getTokenType() != TokenType::LITERAL) {
            continue;
        }
        const std::string &stringArg = token.asString();
        char *arg = new char[stringArg.size() + 1]();
        memcpy(arg, stringArg.c_str(), stringArg.size());
        argv[argc++] = arg;
    }
}

GrepArguments::~GrepArguments() {
    for (int i = 0; i < argc; i++) {
        delete[] argv[i];
    }
    delete[] argv;
}

int &GrepArguments::getArgc() {
    return argc;
}

char **&GrepArguments::getArgv() {
    return argv;
}
