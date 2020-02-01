#ifndef HW01_CLI_IOUTPUTSTREAM_H
#define HW01_CLI_IOUTPUTSTREAM_H

#include <string>

class IOutputStream {
public:
    virtual std::string read() = 0;
};

#endif //HW01_CLI_IOUTPUTSTREAM_H
