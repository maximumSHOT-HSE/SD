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

    BOOST_AUTO_TEST_CASE(testFullInWeakQuotes) {
        std::string command = "cat \"'echo 123 | grep -eEr \"123\"'\" | wc -l | pwd";
        const auto &foundTokens = PipeTokenizer({'\'', '"'}).tokenize(command);
        const std::vector<std::string> &expectedTokens = {
                "cat \"'echo 123 | grep -eEr \"123\"'\" ",
                " wc -l ",
                " pwd"
        };
        BOOST_CHECK_EQUAL_COLLECTIONS(
                expectedTokens.begin(), expectedTokens.end(),
                foundTokens.begin(), foundTokens.end()
        );
    }

    BOOST_AUTO_TEST_CASE(testNoPipe) {
        std::string command = "cat \"'strange command with quotes'\"";
        const auto &foundTokens = PipeTokenizer({'\'', '"'}).tokenize(command);
        const std::vector<std::string> &expectedTokens = {"c at \"'strange command with quotes'\""};
        BOOST_CHECK_EQUAL_COLLECTIONS(
                expectedTokens.begin(), expectedTokens.end(),
                foundTokens.begin(), foundTokens.end()
        );
    }

BOOST_AUTO_TEST_SUITE_END()
