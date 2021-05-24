#include <iostream>
#include "Sqrt.h"
#include "Large_Number/Large_Number.h"
#include "phi_and_lambda.h"
#include "pow/large_number_pow.h"
#include "pow/test_pow.h"
#include "pow/time_testing_pow.h"

#include "Primal_1.h"
#include "Pollard_Rho.h"

#include "discrete_logarithm.h"
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
	string a1 = "431",b1="185761",c1="104729";
	long long a2 = 431, b2 = 185761, c2 = 104729;
	Large_Number a(a1), b(b1), c(c1);
	//cout << DiscreteLogarithm(a,b,c);
	cout << DiscreteLogarithm(a2, b2, c2);
	//startAllTestes();
	/*ln::Number number(12, "43"), exp(5, "43");
	std::cout << ln::powNumber(number, exp) << std::endl;
	std::cout << ln::powNaive(number, exp) << std::endl;*/

	return 0;
}
