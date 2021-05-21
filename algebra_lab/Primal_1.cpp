#include <iostream>
#include <math.h>
#include "Large_Number.h"
#include "sqrt.h"
using namespace std;
void printPrimeFactors(Large_Number n) {
    while (n % 2 == 0) {
        cout << "2\t";
        n = n / 2;
    }
    for (Large_Number i = 3; i < STonelliSQRT(n, Large_Number (2)); i = i + 2) {
        while (n % i == 0) {
            cout << i.to_string() << "\t";
            n = n / i;
        }
    }
    if (n > 2)
        cout << n.to_string() << "\t";
}
void Primal_1() {
    
    Large_Number n = 2934536567645;
    cout << "Prime factors of " << n.to_string() << " are :\t";
    printPrimeFactors(n);
}
