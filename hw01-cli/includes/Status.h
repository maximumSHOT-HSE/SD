#ifndef HW01_CLI_STATUS_H
#define HW01_CLI_STATUS_H

#include <string>

enum class ExitStatus {EXIT = 0, STAY = 1};

class Status {
public:
    Status() = default;

    bool isSuccess() const;

    ExitStatus getExitStatus() const;

    void setExitStatus(ExitStatus exitStatus);

    int getExitCode() const;

    void setExitCode(int statusCode);

    const std::string &getMessage() const;

    void setMessage(const std::string &message);

private:
    int exitCode = 0;
    std::string message = "";
    ExitStatus exitStatus = ExitStatus::STAY;
};


#endif //HW01_CLI_STATUS_H
