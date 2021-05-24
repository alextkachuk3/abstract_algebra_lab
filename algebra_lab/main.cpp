#include <iostream>
//#include "Sqrt.h"
//#include "Large_Number/Large_Number.h"
//#include "phi_and_lambda.h"
//#include "pow/large_number_pow.h"
//#include "pow/test_pow.h"
//#include "pow/time_testing_pow.h"

#include "Primal_1.h"
#include "Pollard_Rho.h"

//#include "discrete_logarithm.cpp"
//#include "discrete_logarithm.h"
using namespace std;

void startAllTestes()
{
	{ // Tests for large_number_pow
		TestRunner tr;
		RUN_TEST(tr, TestPowNumber);
		RUN_TEST(tr, TestDecomposExp);
		RUN_TEST(tr, TestLength);
		RUN_TEST(tr, TestGcd);
		ttp::startTimeTesting();
	}
}
int main()
{	
	startAllTestes();
	ln::Number number(12, "43"), exp(5, "43");
	std::cout << ln::powNumber(number, exp) << std::endl;
	std::cout << ln::powNaive(number, exp) << std::endl;

	return 0;
}
