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
)

add_library(
        util_exectur_library

        STATIC

        src/ICommandExecutor.cpp
        includes/ICommandExecutor.h

        src/CommandExecutorFactory.cpp
        includes/CommandExecutorFactory.h

        src/EchoExecutor.cpp
        includes/EchoExecutor.h
)

add_library(
        processor_library

        STATIC

        includes/IProcessor.h

        src/LoopProcessor.cpp
        includes/LoopProcessor.h

        src/Status.cpp
        includes/Status.h

        src/Response.cpp
        includes/Response.h
)

add_library(
        command_library

        STATIC

        src/Command.cpp
        includes/Command.h

        src/CommandName.cpp
        includes/CommandName.h

        src/CommandArguments.cpp
        includes/CommandArguments.h

        src/CommandBuilder.cpp
        includes/CommandBuilder.h
)

add_library(
        tokenization_library

        STATIC

        includes/ITokenizer.h

        src/LinearTokenizer.cpp
        includes/LinearTokenizer.h

        src/Token.cpp
        includes/Token.h
)

add_library(
        channel_library

        STATIC

        includes/IInputChannel.h
        includes/IOutputChannel.h

        src/StringChannel.cpp
        includes/StringChannel.h
)

include_directories(src)
include_directories(includes)

target_link_libraries(
        hw01_cli

        LINK_PUBLIC

        tokenization_library
        command_library
        processor_library
        util_executor_library
        channel_library
)

#add_subdirectory(test)
