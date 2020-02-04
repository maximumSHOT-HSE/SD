set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})

add_executable(
        hw01_cli_tests

        executors/WCExecutorTest.cpp
)

target_link_libraries(hw01_cli_tests ${Boost_LIBRARIES})

