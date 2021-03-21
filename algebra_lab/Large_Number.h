//
// Created by aaade on 13.03.2021.
//

#ifndef ZA_LARGE_NUMBER_H
#define ZA_LARGE_NUMBER_H
#include <vector>
#include "cmath"

using namespace std;
class Large_Number {
public:
    vector<unsigned int> value;
    Large_Number* N;
    const unsigned int halfСheck = pow(2,16);
    const unsigned int check = pow(2,31);
public:
    Large_Number operator+(Large_Number &other);
    Large_Number operator-(Large_Number &other);
    bool operator>(Large_Number &other);
    bool operator<(Large_Number &other);
    bool operator==(Large_Number &other);
    Large_Number operator*(Large_Number &other);
    Large_Number operator/(Large_Number &other);
    Large_Number operator++();



};


#endif //ZA_LARGE_NUMBER_H
