cmake_minimum_required(VERSION 3.10)

set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})

add_definitions(-DBOOST_TEST_DYN_LINK)

add_executable(
        hw01_cli_tests

        main.cpp

        channels/StringChannelTest.cpp
        tokenizers/TokenTest.cpp
        tokenizers/LinearTokenizerTest.cpp
)

target_link_libraries(
        hw01_cli_tests
        cli
        ${Boost_LIBRARIES}
)

enable_testing()
add_test(cli_unit_tests hw01_cli_tests)
