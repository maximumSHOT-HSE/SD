cmake_minimum_required(VERSION 3.10)

#find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${BOOST_ROOT})

add_definitions(-DBOOST_TEST_DYN_LINK)

add_executable(
        hw01_cli_tests

        main.cpp

        channels/StringChannelTest.cpp
        tokenizers/TokenTest.cpp
        tokenizers/LinearTokenizerTest.cpp

        commands/CommandArgumentsTest.cpp
        commands/CommandNameTest.cpp
        commands/CommandTest.cpp
        commands/CommandBuilderTest.cpp

        SubstitutorTest.cpp

        executors/CommandExecutorFactoryTest.cpp
        executors/CatExecutorTest.cpp
        executors/EchoExecutorTest.cpp
        executors/ExitExecutorTest.cpp
        executors/WCExecutorTest.cpp

        processors/LoopProcessorTest.cpp
)

target_link_libraries(
        hw01_cli_tests
        cli
        ${Boost_LIBRARIES}
        stdc++fs
        boost_system
        Boost::unit_test_framework
)

FILE(COPY resources/wc_test_file.txt DESTINATION resources)
FILE(COPY resources/wc_test_file2.txt DESTINATION resources)

enable_testing()
add_test(cli_unit_tests hw01_cli_tests)
