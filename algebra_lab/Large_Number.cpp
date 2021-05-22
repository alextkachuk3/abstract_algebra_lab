//
// Created by aaade on 13.03.2021.
//

#include "Large_Number.h"

bool Large_Number::operator<(const Large_Number &other) const {
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

bool Large_Number::operator>(const Large_Number &other) const {
    return other < *this;
}

bool Large_Number::operator==(const Large_Number &other) const {
    if (*this > other || *this < other)
        return false;
    return true;
}

Large_Number Large_Number::operator+(const Large_Number &other) const {
    Large_Number result, bigger, smaller;
    if (other.value.size() == this->value.size() || *this < other) {
        bigger = other;
        smaller = *this;
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

Large_Number Large_Number::operator-(const Large_Number &other) const {
    Large_Number result;
    if (*this < other) {

        return *this + (*this->N - other);
    }


    for (int i = other.value.size() - 1; i >= 0; i--) {
        int greater_index = i + this->value.size() - other.value.size();
        unsigned int iter_res = this->value[greater_index] - other.value[i];
        if (other.value.size() - i - 1 == result.value.size())
            result.value.insert(result.value.begin(), iter_res);
        else {
            result.value[0] += iter_res;
        }
        if (this->value[greater_index] < other.value[i])
            result.value.insert(result.value.begin(), (unsigned int) (0 - 1));
    }
    return result;
}

Large_Number Large_Number::operator++() {
    for (int i = this->value.size() - 1; i >= 0; i--) {
        if (this->value[i] >= this->check - 1) {
            this->value[i] = (unsigned int) (0);
            this->value[--i] += (unsigned int) (1);
        } else {
            this->value[i] += (unsigned int) (1);
            break;
        }
    }
    return *this;
}

Large_Number Large_Number::modInverse() {
    Large_Number indexA, indexB, one, res;
    one.value.push_back((unsigned int) (1));
    Large_Number g = Large_Number::gcdExtended(*this->N, *this, &indexA, &indexB);
    if (!(g == one)) {
        res.value.push_back((unsigned int) (0));
        return res;
    } else {
        res = (indexA + *this);
    }
    return res;
}

Large_Number Large_Number::gcdExtended(Large_Number a, Large_Number b, Large_Number *indexA, Large_Number *indexB) {
    Large_Number zero;
    zero.value.push_back((unsigned int) (0));
    if (a == zero) {
        indexA->value.push_back((unsigned int) (0));
        indexB->value.push_back((unsigned int) (1));
        return b;
    }
    Large_Number x1, y1;
    Large_Number gcd = gcdExtended(b, a, &x1, &y1);
    *indexA = y1 - (wholePart(a, b)) * x1;
    *indexB = x1;
    return gcd;
}

Large_Number Large_Number::wholePart(Large_Number a, Large_Number b) {
    Large_Number x;
    x.value.push_back((unsigned int) (0));
    while (b > a) {
        b = b - a;
        x.operator++();
    }
    return x;
}

Large_Number Large_Number::operator/(const Large_Number &other) const {
    Large_Number result, x;
    auto temp = other;
    x = temp.modInverse();
    result = *this * x;
    return result;
}


void Large_Number::modN() {
    if (*this < 0) {
        *this += *N;
        modN();
    }

    if (*this > *N--) {
        *this -= *N;
        modN();
    }
}


Large_Number Large_Number::multiply_by_digit(unsigned int digit) {
    Large_Number result;
    result.value.insert(result.value.begin(), (unsigned int) 0);
    for (unsigned int my_digit: value) {
        int index = 0;
        result.value[index] = my_digit * digit;
        unsigned int quotient = 0;
        unsigned int temp = my_digit;
        while (digit > 0 && sqrt((double) my_digit) * sqrt((double) digit) < halfCheck) {
            if (temp + my_digit < my_digit || temp + my_digit < temp)
                quotient++;
            temp += my_digit;
            digit--;
        }

        if (temp + my_digit * digit < temp || temp + my_digit * digit < my_digit * digit)
            quotient++;
        result.value.insert(result.value.begin(), (unsigned int) quotient);
    }
    if (result.value[0] == 0)
        result.value.erase(result.value.begin());

    return result;
}


Large_Number Large_Number::operator*(const Large_Number &other) const {
    Large_Number result;
    result.value.push_back((unsigned int) 0);
    for (int i = other.value.size() - 1; i >= 0; i--) {
        unsigned int digit = other.value[i];
        auto temp = *this;
        Large_Number adding = temp.multiply_by_digit(digit);
        int number_shifts = other.value.size() - 1 - i;
        while (number_shifts > 0) {
            adding.value.push_back((unsigned int) 0);
            number_shifts--;
        }
        adding.modN();
        result = result + adding;
    }
    return result;
}


bool Large_Number::operator<(int i) {
    if (value.size() > 1)
        return false;
    if (value.size() < 1)
        return true;
    return value[0] < i;
}

Large_Number::Large_Number(const Large_Number &other) :
                N(other.N),
                value(other.value){}

Large_Number::Large_Number() {

}

Large_Number Large_Number::operator=(const Large_Number &other) {
    (*this).N = other.N;
    (*this).value = other.value;
    return *this;
}

Large_Number Large_Number::operator+=(const Large_Number &other) {
    *this = *this + other;
    return Large_Number(*this);
}

Large_Number Large_Number::operator-=(const Large_Number &other) {
    *this = *this - other;
    return Large_Number(*this);
}

Large_Number Large_Number::operator%(const Large_Number &other) const {

    auto quotient = *this / other;
    auto product = quotient * other;
    return *this - product;

}

Large_Number::Large_Number(unsigned int number) {
    (*this).value.push_back(number);
}

Large_Number::Large_Number(string s) {


    do{

        string digit_str;
        if(s.length() >= 8){
            digit_str = s.substr(s.length() - 8, 8);
            s.erase(s.length() - 8,8);
        }
        else{
            digit_str = s;
            s.clear();
        }
        unsigned int x;
        stringstream ss;
        ss << hex << digit_str;
        ss >> x;

        value.insert(value.begin(), x);

    }while (s.length() > 0);
}

Large_Number Large_Number::operator++(int) {
    auto temp = *this;
    ++(*this);
    return temp;
}

std::string Large_Number::to_string() const  {
    std::stringstream stream;
    for (auto &i : value) {
        stream << std::setfill('0')
               << std::setw(sizeof(int32_t)*2)
               << std::hex << i;
    }
    auto result = stream.str();
    result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
    return result;
}

std::ostream &operator<<(ostream &os, const Large_Number &number) {
    os << number.to_string();
    return os;
}
