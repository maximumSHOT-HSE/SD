#include <Shell.h>

#include <LoopProcessor.h>
#include <iostream>

void Shell::run() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        Response response = processor->process(
                input,
                *environment
        );

        StringChannel output = response.getStringChannel();
        std::cout << output.read() << std::endl;
    }
}

Shell::Shell() :
        processor(new LoopProcessor()),
        environment(new Environment()) {
}

Shell::~Shell() {
    delete processor;
    delete environment;
}
