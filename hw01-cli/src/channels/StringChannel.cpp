#include <channels/StringChannel.h>

bool StringChannel::empty() const {
    return buffer.empty();
}

std::string StringChannel::read() {
    std::string helper;
    std::swap(helper, buffer);
    return helper;
}

void StringChannel::write(const std::string &x) {
    buffer += x;
}

void StringChannel::clear() {
    buffer.clear();
}
