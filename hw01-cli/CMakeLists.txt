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

        src/CommandExecutor.cpp
        includes/CommandExecutor.h

        src/CommandExecutorFactory.cpp
        includes/CommandExecutorFactory.h
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

#add_library(
#        stream_library
#
#        STATIC
#
#        includes/IInputStream.h
#        includes/IOutputStream.h
#)

include_directories(src)
include_directories(includes)

target_link_libraries(
        hw01_cli

        LINK_PUBLIC

        tokenization_library
        command_library
        processor_library

        util_executr_library
)

#add_subdirectory(test)
