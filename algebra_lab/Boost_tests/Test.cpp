//
// Created by polina on 23.05.2021.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "../Large_Number/Large_Number.h"

struct LN {

    LN() {
        firstNum = new Large_Number();
        secondNum = new Large_Number();
    }

    ~LN() {
        delete firstNum;
        delete secondNum;
    }

    Large_Number *firstNum;
    Large_Number *secondNum;

};

BOOST_FIXTURE_TEST_CASE(Sum, LN)
{
    firstNum->value.push_back((unsigned int)(0));
    secondNum->value.push_back((unsigned int)(30));
    Large_Number result = *firstNum + *secondNum;
    cout << result.to_string();
    BOOST_CHECK_EQUAL(result.to_string(), "10000001e");

    firstNum->value.push_back((unsigned int)(0));
    secondNum->value.push_back((unsigned int)(-30));
    result = *firstNum + *secondNum;
    BOOST_CHECK_EQUAL(result.to_string(), "10000001fffffffe2");

}

BOOST_FIXTURE_TEST_CASE(Minus, LN)
{
    firstNum->value.push_back((unsigned int)(22));
    secondNum->value.push_back((unsigned int)(12));
    Large_Number result = *firstNum - *secondNum;
    BOOST_CHECK_EQUAL(result.to_string(), "a");

    firstNum->value.push_back((unsigned int)(60));
    secondNum->value.push_back((unsigned int)(123456));
    result = *firstNum - *secondNum;
    BOOST_CHECK_EQUAL(result.to_string(), "9fffe1dfc");

    firstNum->value.push_back((unsigned int)(-60));
    secondNum->value.push_back((unsigned int)(123456));
    result = *firstNum - *secondNum;
    BOOST_CHECK_EQUAL(result.to_string(), "9fffe1dfcfffe1d84");
}

BOOST_FIXTURE_TEST_CASE(Multiple1, LN)
{
    Large_Number result;
    firstNum->value.push_back((unsigned int)(56));
    cout << secondNum->to_string() << endl;
    secondNum->value.push_back((unsigned int)(6784));
    cout << secondNum->to_string() << endl;
    result = *firstNum * *secondNum;
    BOOST_CHECK_EQUAL(result.to_string(), "10005cc00");

}

BOOST_FIXTURE_TEST_CASE(Multiple2, LN)
{
    Large_Number result;
    firstNum->value.push_back((unsigned int)(36));
    cout << secondNum->to_string() << endl;
    secondNum->value.push_back((unsigned int)(684));
    cout << secondNum->to_string() << endl;
    result = *firstNum * *secondNum;
    BOOST_CHECK_EQUAL(result.to_string(), "100006030");

}