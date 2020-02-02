#ifndef HW01_CLI_STATUS_H
#define HW01_CLI_STATUS_H

#include <string>

class Status {
public:
    Status() = default;

    bool isSuccess() const;
private:
    int statusCode = 0;
    std::string message = "";
};


#endif //HW01_CLI_STATUS_H
