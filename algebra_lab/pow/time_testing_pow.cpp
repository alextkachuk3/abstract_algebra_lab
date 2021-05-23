#include "time_testing_pow.h"

namespace ttp
{
	void startTesting(float maxTime, std::size_t numberOfOperations)
	{
		std::random_device rd;
		std::mt19937 mersenne(rd());
		std::cout << "Testing pow.\nNumber of operations: " 
			<< numberOfOperations << std::endl;
		ln::Number number = ln::Number(unsigned(mersenne())),
			exp = ln::Number(unsigned(mersenne()%50000)),
			modulus = ln::Number(unsigned(320011));
		float time = 0.f;
		ln::Number currentExp = exp;
		while (time < maxTime)
		{
			time = powTesting(number, currentExp, modulus, numberOfOperations);
			currentExp *= 2;
		}
		
		std::cout << "\nTesting is finished." << std::endl;
	}
	void printResult(const std::string title, float time, const ln::Number& number)
	{
		std::cout << title << " { time: " 
				<< time << "s,\tresult: " 
				<< number << "}" << std::endl;
	}
	float powTesting(const ln::Number& number, const ln::Number& exp,
		const ln::Number& modulus, std::size_t numberOfOperations)
	{
		std::string firstName = "Montgomery exponentiation",
			secondName = "Naive exponentiation";
		std::cout << "Number:  " << number
			<< "\nPower:   " << exp << "\nModulus: " << modulus << std::endl;
		float time1 = 0.f;
		ln::Number res = ln::powNumber(number, exp, modulus);
		{
			mtimer::Timer timer(time1);
			for (std::size_t i = 0; i < numberOfOperations; i++)
				ln::powNumber(number, exp, modulus);
		}
		printResult("\n" + firstName, time1, res);
		float time2 = 0;
		res = ln::powNaive(number, exp, modulus);
		{
			mtimer::Timer timer(time2);
			for (std::size_t i = 0; i < numberOfOperations; i++)
				ln::powNaive(number, exp, modulus);
		}
		printResult(secondName + "     ", time2, res);
		std::cout << "\n" + firstName + " is " << unsigned(time2 / time1) << " times faster than "
			<< secondName << std::endl;
		return time1 > time2 ? time1 : time2;
	}
}