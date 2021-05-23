#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "Large_Number.h"

BOOST_AUTO_TEST_SUITE(TwoTwoFour_suite)
BOOST_AUTO_TEST_CASE(testPlus) {
        BOOST_CHECK_EQUAL(2+2, 4);
}
BOOST_AUTO_TEST_CASE(testMult) {
        BOOST_CHECK_EQUAL(2*2, 4);
}
BOOST_AUTO_TEST_SUITE_END()