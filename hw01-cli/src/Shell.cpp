#include <Shell.h>

#include <processors/LoopProcessor.h>
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
        std::cout << output.read();

        if (response.getStatus().getExitStatus() == ExitStatus::EXIT) {
            break;
        }
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
