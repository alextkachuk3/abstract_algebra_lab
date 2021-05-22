#include <iostream>
#include "Sqrt.h"
#include "Large_Number.h"
#include "large_number_pow.h"

using namespace std;

int main()
{	
	cout << "Hello CMake." << endl;
	Large_Number a("9164e20e921b");
	Large_Number b("c85a64c022cfc606dd");
    Large_Number res = (a-b);
    Large_Number exp_res("c85a642ebdedb774c2");

//    res = res.multiply_by_digit(16);
	cout << res.to_string() << endl;
    cout << exp_res.to_string() << endl;
    cout << ((exp_res + res) == *(res.N)) << endl;
    cout << (exp_res + res).to_string()  << endl;
    cout << (*res.N).to_string()  << endl;
	return 0;
}
