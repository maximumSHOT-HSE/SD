#include "Shell.h"
#include "processors/LoopProcessor.h"

#include <iostream>

int Shell::run() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        Response response = processor->process(
                input,
                *environment,
                *factory
        );

        StringChannel output = response.getStringChannel();
        std::cout << output.read();

        if (response.getStatus().getExitStatus() == ExitStatus::EXIT) {
            return response.getStatus().getExitCode();
        }
    }
}

Shell::Shell() :
        processor(new LoopProcessor()),
        environment(new Environment()),
        factory(new CommandExecutorFactory()),

        echoExecutor(new EchoExecutor()),
        exitExecutor(new ExitExecutor()),
        catExecutor(new CatExecutor()),
        pwdExecutor(new PWDExecutor()),
        wcExecutor(new WCExecutor()),
        externalExecutor(new ExternalExecutor()),
        emptyExecutor(new EmptyExecutor()) {

    factory->registerExecutor(CommandName("echo"), echoExecutor);
    factory->registerExecutor(CommandName("exit"), exitExecutor);
    factory->registerExecutor(CommandName("cat"), catExecutor);
    factory->registerExecutor(CommandName("pwd"), pwdExecutor);
    factory->registerExecutor(CommandName("wc"), wcExecutor);
    factory->registerExecutor(CommandName(""), emptyExecutor);
}
