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
    Large_Number result;
    int difference, i;
    unsigned int remainder, whole_part = 0, special_case = 0;
    int thisSize = this->value.size(), otherSize = other.value.size();

    if (thisSize == otherSize) {
        for (i = thisSize - 1; i >= 0; i--) {
            remainder = (this->value[i] + other.value[i]) % 10 + whole_part;
            if (remainder >= 10) {
                remainder %= 10;
                special_case = remainder / 10;
            }
            whole_part = (this->value[i] + other.value[i]) / 10;
            result.value.insert(result.value.cbegin(),remainder);
        }
    } else if (this->operator>(other)) {
        difference = thisSize - otherSize;
        for (i = thisSize - 1; i >= 0; i--) {
            remainder = (this->value[i] + other.value[i - difference]) % 10 + whole_part;
            if (remainder >= 10) {
                remainder %= 10;
                special_case = remainder / 10;
            }
            whole_part = (this->value[i] + other.value[i - difference]) / 10;
            result.value.insert(result.value.cbegin(),remainder);
        }
    } else {
        difference = otherSize - thisSize;
        for (i = otherSize - 1; i >= 0; i--) {
            remainder = (other.value[i] + this->value[i - difference]) % 10 + whole_part;
            if (remainder >= 10) {
                remainder %= 10;
                special_case = remainder / 10;
            }
            whole_part = special_case + (other.value[i] + this->value[i - difference]) / 10;
          result.value.insert(result.value.cbegin(),remainder);
        }
    }
    if (*this->N < (result)) {
        return result - *this->N;
    }
    return result;

}
