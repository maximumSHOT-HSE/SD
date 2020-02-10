#ifndef HW01_CLI_GREPEXECUTOR_H
#define HW01_CLI_GREPEXECUTOR_H

#include <executors/ICommandExecutor.h>

class GrepExecutor : public ICommandExecutor {
public:
    Status execute(const Command &command, StringChannel &inputChannel, StringChannel &outputChannel) const override;

};


#endif //HW01_CLI_GREPEXECUTOR_H
