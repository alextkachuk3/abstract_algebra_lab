//
// Created by aaade on 13.03.2021.
//

#include "Large_Number.h"

bool Large_Number::operator<(Large_Number &other) {
    if (this->value.size() > other.value.size())
        return false;
    if (this->value.size() < other.value.size())
        return true;
    for (int i = 0; i < this->value.size(); i++) {
        if (this->value[i] > other.value[i])
            return false;
        if (this->value[i] < other.value[i])
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

Large_Number Large_Number::operator+(Large_Number &other) {
    Large_Number result, bigger, smaller;
    if (other.value.size() == this->value.size() || *this < other) {
        smaller = *this;
        bigger = other;
    } else {
        bigger = *this;
        smaller = other;
    }
    for (int i = smaller.value.size() - 1; i >= 0; i--) {
        int greater_index = i + this->value.size() - other.value.size();
        unsigned int iter_res = this->value[greater_index] + other.value[i];
        if (other.value.size() - i - 1 == result.value.size())
            result.value.insert(result.value.begin(), iter_res);
        else {
            result.value[0] += iter_res;
        }
        if (this->value[greater_index] < other.value[i])
            result.value.insert(result.value.begin(), (unsigned int) (1));
    }
    return result;
}