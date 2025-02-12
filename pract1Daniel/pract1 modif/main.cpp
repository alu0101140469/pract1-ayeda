#include "BigInteger.hpp"
#include "BigFloat.hpp"
#include <iostream>
using namespace std;

// Daniel Palenzuela Álvarez alu0101140469

int main() {
    BigFloat c, d;
    cout << "Numeros bigfloat:" << endl;
    cout << "Introduce el primer número: ";
    cin >> c;
    cout << "Introduce el segundo número: ";
    cin >> d;

    cout << "Los numeros float son " << c << " y " << d << endl;

    return 0;
}