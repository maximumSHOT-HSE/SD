#ifndef HW01_CLI_IPROCESSOR_H
#define HW01_CLI_IPROCESSOR_H

#include <Response.h>
#include <ITokenizer.h>
#include <string>
#include <Environment.h>

class IProcessor {
public:
    virtual Response process(
            const std::string &s,
            const Environment &environment
    ) = 0;

    virtual ~IProcessor() = default;
};


#endif //HW01_CLI_IPROCESSOR_H
