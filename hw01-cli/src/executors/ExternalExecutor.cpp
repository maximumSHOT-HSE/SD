#include "executors/ExternalExecutor.h"
#include <boost/process.hpp>

namespace bp = boost::process;

Status ExternalExecutor::execute(
        const Command &command,
        StringChannel &inputStream,
        StringChannel &outputStream
) const {

    bp::system(command.asString());

    return Status();
}
