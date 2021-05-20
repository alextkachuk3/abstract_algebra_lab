#include <iostream>
#include "Sqrt.h"
#include "Large_Number.h"
#include "large_number_pow.h"

using namespace std;

int main()
{	
	cout << "Hello CMake." << endl;
	Large_Number a("57970cd7e29336814af");
	Large_Number b(4);
    a.modN();
	cout << a.to_string() << endl;

	return 0;
}
