#ifndef HW01_CLI_RESPONSE_H
#define HW01_CLI_RESPONSE_H

#include <IOutputStream.h>
#include <Status.h>

class Response {
private:
    IOutputStream &outputStream;
    Status status;
};


#endif //HW01_CLI_RESPONSE_H
