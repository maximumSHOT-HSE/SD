#ifndef HW01_CLI_IPROCESSOR_H
#define HW01_CLI_IPROCESSOR_H

#include <Response.h>
#include <ITokenizer.h>
#include <string>

class IProcessor {
public:
    virtual Response process(
            const std::string &s,
            const ITokenizer &tokenizer
    ) = 0;
};


#endif //HW01_CLI_IPROCESSOR_H
