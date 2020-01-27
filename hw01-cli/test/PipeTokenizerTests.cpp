#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE pipe_tokenizer_unit_tests
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "PipeTokenizer.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

BOOST_AUTO_TEST_SUITE(InnerQutoes_suite)

    BOOST_AUTO_TEST_CASE(testFullInFeaw) {
        std::string command = "cat \"'echo 123 | grep -eEr \"123\"'\" | wc -l | pwd";
        const auto &tokens = PipeTokenizer({'\'', '"'}).tokenize(command);
        for (const auto &token : tokens) {
            std::cout << token << "\n";
        }
    }

BOOST_AUTO_TEST_SUITE_END()
