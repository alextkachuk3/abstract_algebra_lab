#include <iostream>
#include "Sqrt.h"
#include "Large_Number.h"
#include "large_number_pow.h"


using namespace std;

int main()
{	
	cout << "Hello CMake." << endl;
	const string max_digit2 = "1000000000000000000000";
    int d = atoi(max_digit2.c_str());
    cout << d << endl;
	std::cout << ln::powNumber(31426, 442);

	return 0;
}
