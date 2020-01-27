set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})

add_executable(pipe_tokenizer_tests PipeTokenizerTests.cpp)

target_link_libraries(pipe_tokenizer_tests ${Boost_LIBRARIES})
target_link_libraries(pipe_tokenizer_tests tokenization_library)
