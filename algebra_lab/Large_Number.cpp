//
// Created by aaade on 13.03.2021.
//

#include "Large_Number.h"

bool Large_Number::operator<(Large_Number &other) {
    if(this->value.size() > other.value.size())
        return false;
    if(this->value.size() < other.value.size())
        return true;
    for(int i = 0; i < this->value.size();i++){
        if(this->value[i] > other.value[i])
            return false;
        if(this->value[i] < other.value[i])
            return true;
    }
    return false;
}


bool Large_Number::operator>(Large_Number &other) {
    return other < *this;
}

bool Large_Number::operator==(Large_Number &other) {
    if (*this > other or *this < other)
        return false;
    return true;
}

void Large_Number::modN() {
    if(*this < 0)
    {
        *this += *N;
        modN();
    }

    if(*this > *N--)
    {
        *this -= *N;
        modN();
    }
}


Large_Number Large_Number::multiply_by_digit(unsigned int digit) {
    Large_Number result;
    result.value.insert(result.value.begin(), (unsigned int)0);
    for(unsigned int my_digit){
        int index = 0;
        result.value[index] = my_digit*digit;
        unsigned int quotient = 0;
        unsigned int temp = my_digit;
        while(digit > 0 && sqrt((double )my_digit)*sqrt((double )digit) < halfСheck){
            if(temp + my_digit < my_digit || temp + my_digit < temp)
                quotient++;
            temp += my_digit;
            digit--;
        }

        if(temp + my_digit*digit < temp || temp + my_digit*digit < my_digit*digit)
            quotient++;
        result.value.insert(result.value.begin(), (unsigned int)quotient);
    }
    if(result.value[0] == 0)
        result.value.erase(result.value.begin());
}


Large_Number Large_Number::operator*(Large_Number &other) {
    vector<Large_Number> adding parts;
    for(unsigned int digit: other.value){

    }
}