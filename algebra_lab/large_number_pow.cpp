#include "large_number_pow.h"

namespace ln
{
	Large_Number pow(const Large_Number& number, const Large_Number& exp)
	{

	}
	unsigned pow(const unsigned& number, const unsigned& exp)
	{
		if (exp == 0) return 1;
		if (exp == 1) return number;
		unsigned base = 10;
		unsigned modulus = 101;
		unsigned numberR = std::pow(base, length(modulus, base));
		numberR %= modulus;
		unsigned rInv = 0, modulusInv = 0;
		unsigned gcs = gcdExtended(numberR, modulus, rInv, modulusInv);
		modulusInv = -1 * modulusInv;
		auto allExp = decomposeExp(exp);//exp = 13 -> allExp = {8, 4, 1}
		std::vector<unsigned> montNumbers(length(exp, 2));//for x^1, x^2, x^4, x^8 ... x^allExp[allExp.size() - 1]
		if (montNumbers.size() == 0) return 1;
		auto montNumber = (number * numberR) % modulus;//montgomery form
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

		return (res * rInv % modulus);
	}
	unsigned length(unsigned number, unsigned base)
	{
		unsigned res = 0;
		while (number > 0)
		{
			number /= base;
			res++;
		}
		return res;
	}
	unsigned gcdExtended(unsigned numberR, unsigned numberN, unsigned& rInv, unsigned& nInv)
	{
		if (numberR == 0)
		{
			rInv = 0;
			nInv = 1;
			return numberN;
		}
		unsigned rInv1, nInv1;
		unsigned gcd = gcdExtended(numberN % numberR, numberR, rInv1, nInv1);
		rInv = nInv1 - (numberN / numberR) * rInv1;
		nInv = rInv1;

		return gcd;
	}
	std::vector<unsigned> decomposeExp(unsigned exp)
	{
		unsigned len = length(exp, 2) - 1;
		std::vector<unsigned> arr;
		unsigned part = std::pow(2, len);
		while (exp > 0)
		{
			if (part <= exp)
			{
				arr.push_back(part);
				exp -= part;
			}
			part /= 2;
		}
		return arr;
	}
	unsigned montgomeryMultiplication(unsigned montNumber1, unsigned montNumber2,
		unsigned numberR, unsigned modulus, unsigned modulusInv)
	{
		auto numberT = montNumber1 * montNumber2;
		auto tModulus = numberT % numberR;
		auto numberU = (numberT + ((modulusInv * tModulus) % numberR) * modulus) / numberR;
		while (numberU > modulus) numberU = numberU - modulus;
		return numberU;//in montgomery form
	}
}