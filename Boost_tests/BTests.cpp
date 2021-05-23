#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "Large_Number.h"

BOOST_AUTO_TEST_SUITE(Large_Number_Tests)

    BOOST_FIXTURE_TEST_CASE(Sum, LN) {
    //        mpz_t v,w;
    x = Large_Number::generate_random_number();
    y = Large_Number::generate_random_number();

    BOOST_CHECK_EQUAL( x + y, Large_Number::generate_random_number());
    //        BOOST_CHECK_THROW(x.NOK(-3, 1), invalid_argument);
    }

    BOOST_FIXTURE_TEST_CASE(Minus, LN) {
    //        mpz_t v,w;
    x = Large_Number::generate_random_number();
    y = Large_Number::generate_random_number();
    //        mpz_init(v,mpz_class(x));
    //        w = mpz_class(y);
    //        BOOST_CHECK_EQUAL( x - y, v - w);
    BOOST_CHECK_THROW(if(x < 0 || y < 0), invalid_argument);
    }

BOOST_AUTO_TEST_SUITE_END()