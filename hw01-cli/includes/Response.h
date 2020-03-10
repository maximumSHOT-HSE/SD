#ifndef HW01_CLI_RESPONSE_H
#define HW01_CLI_RESPONSE_H

#include "Status.h"
#include "channels/StringChannel.h"

#include <sstream>

class Response {
public:
    Response(const Status &status, const StringChannel &stringChannel);

    const Status &getStatus() const;

    const StringChannel &getStringChannel() const;

private:
    Status status;
    StringChannel stringChannel;
};


#endif //HW01_CLI_RESPONSE_H
