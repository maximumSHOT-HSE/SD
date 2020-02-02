#ifndef HW01_CLI_STRINGCHANNEL_H
#define HW01_CLI_STRINGCHANNEL_H

#include <IInputChannel.h>
#include <IOutputChannel.h>
#include <string>

class StringChannel :
        public IInputChannel<std::string>,
        public IOutputChannel<std::string> {
public:
    bool empty() const override;

    std::string read() override;

    void write(const std::string &x) override;

    ~StringChannel() override = default;

private:
    std::string buffer;
};


#endif //HW01_CLI_STRINGCHANNEL_H
