cmake_minimum_required(VERSION 3.10)
project(hw01_cli)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        hw01_cli

        src/main.cpp

        src/Shell.cpp
        includes/Shell.h

        src/Token.cpp
        includes/Token.h

        includes/IProcessor.h

        src/Status.cpp
        includes/Status.h

        src/Response.cpp
        includes/Response.h
)

add_library(
        tokenization_library

        STATIC

        includes/ITokenizer.h

        src/LinearTokenizer.cpp
        includes/LinearTokenizer.h
)

add_library(
        stream_library

        STATIC

        includes/IInputStream.h
        includes/IOutputStream.h
)

include_directories(src)
include_directories(includes)

target_link_libraries(hw01_cli LINK_PUBLIC tokenization_library)

#add_subdirectory(test)
