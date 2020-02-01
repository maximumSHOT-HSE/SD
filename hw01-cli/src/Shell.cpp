#include <Shell.h>

#include <LoopProcessor.h>
#include <LinearTokenizer.h>
#include <iostream>
#include <sstream>

void Shell::run() {
    std::string input;
    while (true) {
        std::cin >> input;
        Response response = processor->process(
                input,
                *environment
        );
    }
}

Shell::Shell() :
        processor(new LoopProcessor()),
        environment(new Environment) {
//    environment->registerExecutor()
}

Shell::~Shell() {
    delete processor;
    delete environment;
}
