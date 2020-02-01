#ifndef HW01_CLI_IINPUTSTREAM_H
#define HW01_CLI_IINPUTSTREAM_H

#include <string>

class IInputStream {
public:
    virtual std::string write() = 0;
};

#endif //HW01_CLI_IINPUTSTREAM_H
