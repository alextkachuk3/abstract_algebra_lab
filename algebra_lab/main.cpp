#include <iostream>
#include "Sqrt.h"
#include "Large_Number.h"
#include "large_number_pow.h"

using namespace std;

int main()
{	
	cout << "Hello CMake." << endl;
	Large_Number a("4");
	Large_Number b("4");
    Large_Number res = (b/a);
//    res = res.multiply_by_digit(16);
	cout << res.to_string() << endl;
    cout << a.N->to_string() << endl;
	return 0;
}
