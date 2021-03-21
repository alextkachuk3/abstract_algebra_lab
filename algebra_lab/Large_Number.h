//
// Created by aaade on 13.03.2021.
//

#ifndef ZA_LARGE_NUMBER_H
#define ZA_LARGE_NUMBER_H
#include <vector>
using namespace std;
class Large_Number {
public:
    vector<unsigned int> value;
    const Large_Number* N;

    Large_Number multiply_by_digit(unsigned int digit);

    void modN();
public:
    Large_Number operator+(Large_Number &other);
    Large_Number operator-(Large_Number &other);
    bool operator>(Large_Number &other);
    bool operator<(Large_Number &other);
    bool operator==(Large_Number &other);
    Large_Number operator*(Large_Number &other);
    Large_Number operator/(Large_Number &other);





};


#endif //ZA_LARGE_NUMBER_H
