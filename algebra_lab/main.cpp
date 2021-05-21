#include <iostream>
//#include "Sqrt.h"
//#include "Large_Number.h"
#include "large_number_pow.h"
#include "phi_and_lambda.h"
//#include "Primal_1.cpp"
//#include "discrete_logarithm.cpp"
#include "BigInt.h"

using namespace std;

int main()
{	
	//{ // Tests for large_number_pow
	//	TestRunner tr;
	//	RUN_TEST(tr, TestPowNumber);
	//	RUN_TEST(tr, TestDecomposExp);
	//	RUN_TEST(tr, TestLength);
	//	RUN_TEST(tr, TestGcd);

	//}
	//cout << "Hello CMake." << endl;
	//const string max_digit2 = "1000000000000000000000";
 //   int d = atoi(max_digit2.c_str());
 //   cout << d << endl;

	//std::cout << ln::powNumber(31426, 442);

	/*BigInt q = 10;

	cout << q;*/

	//std::cout << ln::powNumber(31426, 442);

	std::cout << ln::powNumber(3465342, 12) << std::endl;
	std::cout << ln::powNaive(3465342, 12) << std::endl;




	long long q;
	cin >> q;
	while (q)
	{
		cout << "phi:" << phi(q) << endl;
		cout << "lambda:" << lambda(q) << endl;
		cin >> q;
	}

	cout << p_h_tests() << endl;

	return 0;
}
