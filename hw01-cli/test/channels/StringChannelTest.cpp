#include <boost/test/unit_test.hpp>
#include <channels/StringChannel.h>

BOOST_AUTO_TEST_SUITE(StringChannelSuite)

    BOOST_AUTO_TEST_CASE(testEmpty) {
        StringChannel stringChannel;

        BOOST_CHECK_EQUAL(true, stringChannel.empty());
    }

BOOST_AUTO_TEST_SUITE_END()
