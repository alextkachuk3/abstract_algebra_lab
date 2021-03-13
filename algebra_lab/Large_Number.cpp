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