#include "executors/PWDExecutor.h"

#include <iostream>
#include <experimental/filesystem>

Status PWDExecutor::execute(
        const Command &command,
        StringChannel &inputStream,
        StringChannel &outputStream
) const {

    using namespace std::experimental::filesystem;

    outputStream.write(absolute(current_path()));
    outputStream.write("\n");

    // TODO: add newline character (multi platform)

    return Status();
}
