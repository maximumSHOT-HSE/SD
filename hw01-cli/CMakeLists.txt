cmake_minimum_required(VERSION 3.10)
project(hw01_cli)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        hw01_cli

        src/main.cpp

        src/Shell.cpp
        includes/Shell.h

        src/Environment.cpp
        includes/Environment.h

#       ========================
        src/executors/ICommandExecutor.cpp
        includes/executors/ICommandExecutor.h

        src/commands/CommandExecutorFactory.cpp
        includes/commands/CommandExecutorFactory.h

        src/executors/EchoExecutor.cpp
        includes/executors/EchoExecutor.h

#       ========================
        includes/processors/IProcessor.h

        src/processors/LoopProcessor.cpp
        includes/processors/LoopProcessor.h

        src/Status.cpp
        includes/Status.h

        src/Response.cpp
        includes/Response.h

#       ========================
        src/commands/Command.cpp
        includes/commands/Command.h

        src/commands/CommandName.cpp
        includes/commands/CommandName.h

        src/commands/CommandArguments.cpp
        includes/commands/CommandArguments.h

        src/commands/CommandBuilder.cpp
        includes/commands/CommandBuilder.h

        #       ========================
        includes/tokenizers/ITokenizer.h

        src/tokenizers/LinearTokenizer.cpp
        includes/tokenizers/LinearTokenizer.h

        src/Token.cpp
        includes/Token.h

#       ========================
        includes/channels/IInputChannel.h
        includes/channels/IOutputChannel.h

        src/channels/StringChannel.cpp
        includes/channels/StringChannel.h

#       ========================
        src/Substitutor.cpp
        includes/Substitutor.h

#       ========================
        src/executors/ExitExecutor.cpp
        includes/executors/ExitExecutor.h
)

include_directories(src)
include_directories(includes)

#add_subdirectory(test)
