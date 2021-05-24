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
	//startAllTestes();
	//Large_Number a(3);
	//Large_Number b(9);
	//Large_Number c(17);
	//cout << DiscreteLogarithm(3,9,17).to_string();
	//cout << (a <= b);
	//long long q;
	//cin >> q;
	//while (q)
	//{
	//	cout << "phi:" << phi(q) << endl;
	//	cout << "lambda:" << lambda(q) << endl;
	//	cin >> q;
	//}

	//cout << p_h_tests() << endl;
	
	//std::cout << (Large_Number(100) / Large_Number(50)).to_string();

	long long  n = 2934536785456656;
	
	printPrimeFactors(n);
	pollard_rh0(n);
	return 0;
}
