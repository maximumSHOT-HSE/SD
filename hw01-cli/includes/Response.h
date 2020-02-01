#ifndef HW01_CLI_RESPONSE_H
#define HW01_CLI_RESPONSE_H

#include <sstream>
#include <Status.h>

class Response {
public:
    Response(const Status &status);

    const Status &getStatus() const;

private:
    Status status;
    // TODO: add stream here
};


#endif //HW01_CLI_RESPONSE_H
