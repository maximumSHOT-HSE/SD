#ifndef HW01_CLI_IINPUTCHANNEL_H
#define HW01_CLI_IINPUTCHANNEL_H


template<class T>
class IInputChannel {
public:
    virtual bool empty() const = 0;

    virtual T read() = 0;

    virtual ~IInputChannel() = default;

};


#endif //HW01_CLI_IINPUTCHANNEL_H
