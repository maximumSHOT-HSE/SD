#ifndef HW01_CLI_IPROCESSOR_H
#define HW01_CLI_IPROCESSOR_H

#include "Response.h"
#include "tokenizers/ITokenizer.h"
#include "Environment.h"

#include <string>

class IProcessor {
public:
    virtual Response process(
            const std::string &s,
            Environment &environment
    ) = 0;

    virtual ~IProcessor() = default;
};


#endif //HW01_CLI_IPROCESSOR_H
