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

    const Large_Number *N;

    Large_Number multiply_by_digit(unsigned int digit);

    void modN();


    //const unsigned int halfСheck = pow(2, 16);
    //const unsigned int check = pow(2, 31);

public:
    Large_Number operator+(Large_Number &other);

    Large_Number operator-(Large_Number &other);

    bool operator>(Large_Number &other);

    bool operator<(Large_Number &other);

    bool operator==(Large_Number &other);

    Large_Number operator*(Large_Number &other);

    Large_Number operator/(Large_Number &other);

    Large_Number operator++();

    Large_Number gcdExtended(Large_Number a, Large_Number b, Large_Number *indexA, Large_Number *indexB);

    Large_Number modInverse();

    Large_Number wholePart(Large_Number a, Large_Number b);

    bool operator<(int i);

};


#endif //ZA_LARGE_NUMBER_H
