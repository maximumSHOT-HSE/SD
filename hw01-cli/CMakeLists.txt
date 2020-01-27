cmake_minimum_required(VERSION 3.10)
project(hw01_cli)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        hw01_cli
        src/main.cpp
)

add_library(
        tokenization_library

        STATIC

        src/PipeTokenizer.cpp
        includes/PipeTokenizer.h
        includes/ITokenizer.h
)

include_directories(src)
include_directories(includes)

target_link_libraries(hw01_cli LINK_PUBLIC tokenization_library)

add_subdirectory(test)
