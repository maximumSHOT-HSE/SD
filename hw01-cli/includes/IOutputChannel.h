#ifndef HW01_CLI_IOUTPUTCHANNEL_H
#define HW01_CLI_IOUTPUTCHANNEL_H


template<class T>
class IOutputChannel {
public:
    virtual void write(const T &x) = 0;

    virtual ~IOutputChannel() = default;

};


#endif //HW01_CLI_IOUTPUTCHANNEL_H
