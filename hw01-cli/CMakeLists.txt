cmake_minimum_required(VERSION 3.10)
project(hw01_cli)

set(CMAKE_CXX_STANDARD 17)

add_library(
        cli

        STATIC

        src/Shell.cpp
        includes/Shell.h

        src/Environment.cpp
        includes/Environment.h

        #       ========================
        src/executors/ICommandExecutor.cpp
        includes/executors/ICommandExecutor.h

        src/executors/CommandExecutorFactory.cpp
        includes/commands/CommandExecutorFactory.h

        src/executors/EchoExecutor.cpp
        includes/executors/EchoExecutor.h

        src/executors/ExitExecutor.cpp
        includes/executors/ExitExecutor.h

        src/executors/CatExecutor.cpp
        includes/executors/CatExecutor.h

        src/executors/PWDExecutor.cpp
        includes/executors/PWDExecutor.h

        src/executors/WCExecutor.cpp
        includes/executors/WCExecutor.h

        src/executors/ExternalExecutor.cpp
        includes/executors/ExternalExecutor.h

        src/executors/EmptyExecutor.cpp
        includes/executors/EmptyExecutor.h

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

        src/tokenizers/Token.cpp
        includes/tokenizers/Token.h

        #       ========================
        includes/channels/IInputChannel.h
        includes/channels/IOutputChannel.h

        src/channels/StringChannel.cpp
        includes/channels/StringChannel.h

        #       ========================
        src/Substitutor.cpp
        includes/Substitutor.h
)

add_executable(
        hw01_cli

        src/main.cpp
)

target_link_libraries(
        hw01_cli
        stdc++fs
        cli
)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
include_directories(${Boost_INCLUDE_DIRS})
find_package(Boost COMPONENTS filesystem REQUIRED)

target_link_libraries(
        hw01_cli
        ${Boost_LIBRARIES}
        stdc++fs
        boost_system
)

include_directories(src)
include_directories(includes)

add_subdirectory(test)
