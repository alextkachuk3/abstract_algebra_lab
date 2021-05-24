//
// Created by aaade on 13.03.2021.
//

#ifndef ZA_LARGE_NUMBER_H
#define ZA_LARGE_NUMBER_H

#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <random>
using namespace std;

class Large_Number {
public:
    vector<unsigned int> value;

    const Large_Number *N;

    const string N_str = "57970cd7e29336813af";

    Large_Number multiply_by_digit(unsigned int digit);

    void modN();


    const unsigned int halfCheck = pow(2, 16);
    const unsigned int check = pow(2, 31);

public:
    // Set your N, otherwise you will get a default value: 57970cd7e29336813af
    Large_Number();

    Large_Number(unsigned int number);
    Large_Number(unsigned int number, string mod);
    Large_Number(string s);

    Large_Number(string num, string mod);

    Large_Number(string s,bool isN);

    Large_Number(const Large_Number &other);

    void setN(string s);

    Large_Number operator+(const Large_Number &other) const;

    Large_Number operator-(const Large_Number &other) const;

    Large_Number operator=(const Large_Number &other);

    Large_Number operator+=(const Large_Number &other);

    Large_Number operator-=(const Large_Number &other);

    Large_Number operator%(const Large_Number &other) const;

    bool operator>(const Large_Number &other) const;

    bool operator<(const Large_Number &other) const;

    bool operator==(const Large_Number &other) const;

    bool operator<=(const Large_Number& other) const;

    bool operator>=(const Large_Number& other) const;

    Large_Number operator*(const Large_Number &other) const;

    Large_Number operator/(const Large_Number &other) const;

    Large_Number operator++();

    Large_Number operator++(int);

    Large_Number gcdExtended(Large_Number a, Large_Number b, Large_Number &indexA, Large_Number &indexB, bool &indexA_isNeg,bool &indexB_isNeg);

    Large_Number modInverse();

    Large_Number generate_random_number();

    Large_Number wholePart(Large_Number a, Large_Number b);

    bool operator<(int i);

    std::string to_string() const;

private:
    bool compare_strings(string s1, string s2);
};
std::ostream& operator<<(std::ostream& out, const Large_Number& number);

#endif //ZA_LARGE_NUMBER_H
