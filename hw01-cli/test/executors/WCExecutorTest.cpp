#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE WCExecutor_unit_tests
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <executors/WCExecutor.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>


BOOST_AUTO_TEST_SUITE(WCExecutorSuite)

    BOOST_AUTO_TEST_CASE(testFullInWeakQuotes) {
        BOOST_CHECK_EQUAL("a", "a");
    }

BOOST_AUTO_TEST_SUITE_END()
