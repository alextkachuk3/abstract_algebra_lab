#pragma once
#include "large_number_pow.h"
#include "../my_timer.h"
#include <iostream>
#include <random>
namespace ttp//time testing pow
{
	void startTimeTesting(float maxTime = 10.f, std::size_t numberOfOperations = 10);
	void printResult(const std::string title, float time, const ln::Number& number);
	float powTesting(const ln::Number& number, const ln::Number& exp, 
		const ln::Number& modulus, std::size_t numberOfOperations);
}