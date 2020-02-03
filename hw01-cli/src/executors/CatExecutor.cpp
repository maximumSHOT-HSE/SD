#include "executors/CatExecutor.h"
#include <assert.h>
#include <algorithm>
#include <fstream>

Status CatExecutor::execute(
        const CommandArguments &commandArguments,
        StringChannel &inputStream,
        StringChannel &outputStream
) const {

    // TODO: add check: len(args) >= 1

    const auto &arguments = commandArguments.asTokensVector();

    for (const auto &argument : arguments) {
        if (argument.getTokenType() != TokenType::LITERAL) {
            continue;
        }
        std::ifstream fin(argument.asString()); // TODO: add exceptions
        for (char c; fin.get(c);) {
            outputStream.write(c);
        }
    }

    return Status();
}
