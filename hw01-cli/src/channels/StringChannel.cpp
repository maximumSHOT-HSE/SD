#include <channels/StringChannel.h>
#include <fstream>

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

void StringChannel::write(char c) {
    buffer.push_back(c);
}

void StringChannel::writeFile(const std::string &fileName) {
    std::ifstream fin(fileName);
    for (char c; fin.get(c);) {
        write(c);
    }
}
