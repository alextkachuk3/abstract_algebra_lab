#include <iostream>
//#include "Sqrt.h"
//#include "Large_Number.h"
#include "phi_and_lambda.h"
#include "pow/large_number_pow.h"
#include "pow/test_pow.h"
#include "pow/time_testing_pow.h"

#include "Primal_1.h"
#include "Pollard_Rho.h"

//#include "discrete_logarithm.cpp"
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
	return 0;
}
