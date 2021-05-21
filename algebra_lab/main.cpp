#include <iostream>
#include "Sqrt.h"
#include "Large_Number.h"
#include "large_number_pow.h"
#include "unit_test_framework.h"
#include "test_pow.h"
#include "phi_and_lambda.h"

using namespace std;

int main()
{	
	{ // Tests for large_number_pow
		TestRunner tr;
		RUN_TEST(tr, TestPowNumber);
		RUN_TEST(tr, TestDecomposExp);
		RUN_TEST(tr, TestLength);
		RUN_TEST(tr, TestGcd);
	}
	cout << "Hello CMake." << endl;
	const string max_digit2 = "1000000000000000000000";
    int d = atoi(max_digit2.c_str());
    cout << d << endl;
	//std::cout << ln::powNumber(31426, 442);

	return 0;
}
