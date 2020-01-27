#include <iostream>
#include <string>
#include <optional>
#include "PipeTokenizer.h"
#include <unordered_set>

int main() {

    while (true) {
        std::string command;
        getline(std::cin, command);

        PipeTokenizer pipeTokenizer({'\'', '"'});
        std::vector<std::string> pipeTokens = pipeTokenizer.tokenize(command);

        for (const auto &token : pipeTokens) {
            std::cout << "\"" << token << "\"\n";
        }

        if (command == "exit") {
            break;
        }
    }

    return 0;
}
