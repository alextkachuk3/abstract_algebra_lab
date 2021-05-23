#pragma once
#include "Large_Number.h"
#include <math.h>
#include <vector>
namespace ln//large number
{
	using Number = long long;
	/**
	* \brief Modular exponentiation naive algorithm for raising a number to a power (by modulus).
	* \param number - a number that will be raised
	* \param exp - exponent or power
	* \returns - number^exp mod modulus
	*/
	Number powNaive(const Number& number, const Number& exp, const Number& modulus = Number(unsigned(3571)));
	/**
	* \brief Montgomery modular exponentiation algorithm for raising a number to a power (by modulus).
	* 
	* Using exponentiation by squaring and Montgomery modular multiplication.
	* 
	* \param number - a number that will be raised
	* \param exp - exponent or power
	* \returns - number^exp mod modulus
	*/
	Number powNumber(const Number& number, const Number& exp, const Number& modulus = Number(unsigned(3571)));
	/**
	* \brief Decomposes a number into an array using its binary representation.
	*
	* Example: exp = 13 = 2^0 + 2^2 + 2^3 = 1 + 4 + 8, result = {1,4,8}.
	*
	* \param exp - a number that will be decomposed
	*/
	std::vector<Number> decomposeExp(Number exp, const Number& modulus);
	/**
	* \brief Method for performing fast modular multiplication.
	*
	* \param montNumber1 - first number in Montgomery form
	* \param montNumber2 - second number in Montgomery form
	* \param numberR - number r in Montgomery algorithm
	* \param modulusInv - number n' in Montgomery algorithm
	* 
	* \returns the result of multiplication in Montgomery form
	*/
	Number montgomeryMultiplication(const Number& montNumber1, const Number& montNumber2,
		const Number& numberR, const Number& modulus, const Number& modulusInv);
	/**
	* \brief Calculates the length of a number in a number system with a base.
	* 
	* \param base - base of a number system
	* \returns length of number
	*/
	unsigned length(Number number, const Number& base);
	/**
	* \brief Extended Euclidean algorithm.
	* 
	* \param rInv will be the modular multiplicative inverse of numberR modulo numberN 
	* \param nInv will be the modular multiplicative inverse of numberN modulo numberR.
	*/
	Number gcdExtended(const Number& numberR, const Number& numberN, Number& rInv, Number& nInv);
	/**
	* \brief Returns number mod modulus.
	* 
	* It is not equal operator%.
	*/
	Number mod(const Number& number, const Number& modulus);
}
