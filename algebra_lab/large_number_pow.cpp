#include "large_number_pow.h"
#include <iostream>
namespace ln
{
    Number powNaive(const Number& number, const Number& exp, const Number& modulus)
    {
        Number res = Number(unsigned(1));
        for (Number i = Number(unsigned(1)); i < exp + Number(unsigned(1)); i++)
        {
            res = (res * (number % modulus)) % modulus;
        }
        return res % modulus;
    }
    Number powNumber(const Number& number, const Number& exp, const Number& modulus)
    {
        if (exp == Number(unsigned(0))) return Number(unsigned(1));
        if (exp == Number(unsigned(1))) return mod(number, modulus);
        unsigned base = 10;
        //if(number.N) modulus = *(number.N);// will take in Large_Nuber as N
        unsigned modulusLength = length(modulus, Number(base));
        Number numberR = Number(unsigned(0));
        if (modulusLength > 9) numberR = powNumber(Number(base), Number(modulusLength), modulus);
        else numberR = Number(unsigned(pow(base, modulusLength))) % modulus;//10^9 < MAX_UNSIGNED
        Number rInv = Number(unsigned(0)), modulusInv = Number(unsigned(0));
        Number gcs = gcdExtended(numberR, modulus, rInv, modulusInv);
        modulusInv = Number(unsigned(0)) - modulusInv;
        auto allExp = decomposeExp(exp, modulus);//exp = 13 -> allExp = {8, 4, 1}
        std::vector<Number> montNumbers(length(exp, 2));//for x^1, x^2, x^4, x^8 ... x^allExp[allExp.size() - 1]
        if (montNumbers.size() == 0) return Number(unsigned(1));
        auto montNumber = mod(number * numberR, modulus);//montgomery form
        montNumbers[0] = montNumber;
        for (std::size_t i = 1; i < montNumbers.size(); i++)
        {
            montNumbers[i] = montgomeryMultiplication(montNumber,
                montNumber, numberR, modulus, modulusInv);
            montNumber = montNumbers[i];
        }
        auto res = montNumbers[length(allExp[0], 2) - 1];
        for (std::size_t i = 1; i < allExp.size(); i++)
        {
            res = montgomeryMultiplication(res,
                montNumbers[length(allExp[i], 2) - 1], numberR, modulus, modulusInv);
        }
        return mod(res * rInv, modulus);
    }
    std::vector<Number> decomposeExp(Number exp, const Number& modulus)
    {
        unsigned len = length(exp, 2) - 1;
        std::vector<Number> arr;
        Number part = Number(unsigned(0));
        if (len > 31) part = powNumber(Number(unsigned(2)), Number(len),modulus);
        else part = Number(unsigned(pow(2, len)));
        while (exp > Number(unsigned(0)))
        {
            if (part < exp + Number(unsigned(1)))
            {
                arr.push_back(part);
                exp = exp - part;
            }
            part = part / Number(unsigned(2));
        }
        return arr;
    }
    unsigned length(Number number, const Number& base)
    {
        unsigned res = 0;
        while (number > Number(unsigned(0)))
        {
            number = number / base;
            res++;
        }
        return res;
    }
    Number gcdExtended(const Number& numberR, const Number& numberN, Number& rInv, Number& nInv)
    {
        if (numberR == Number(unsigned(0)))
        {
            rInv = Number(unsigned(0));
            nInv = Number(unsigned(1));
            return numberN;
        }
        Number rInv1 = Number(unsigned(0)), nInv1 = Number(unsigned(0));
        Number gcd = gcdExtended(numberN % numberR, numberR, rInv1, nInv1);
        rInv = nInv1 - (numberN / numberR) * rInv1;
        nInv = rInv1;

        return gcd;
    }
    Number montgomeryMultiplication(const Number& montNumber1, const Number& montNumber2,
        const Number& numberR, const Number& modulus, const Number& modulusInv)
    {
        Number numberT = montNumber1 * montNumber2;
        Number tModulus = numberT % numberR;
        Number numberU = (numberT + (mod(modulusInv * tModulus, numberR)) * modulus) / numberR;
        while (numberU > modulus) numberU = numberU - modulus;
        return numberU;//in montgomery form
    }
    Number mod(const Number& number, const Number& modulus)
    {
        return (number % modulus + modulus) % modulus;
    }
}