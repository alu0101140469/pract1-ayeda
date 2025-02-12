#include "BigInteger.hpp"
#include <iostream>
using namespace std;

// Daniel Palenzuela Álvarez alu0101140469

int main() {
    BigInteger a, b;
    cout << "Cálculo del máximo común divisor " << endl;
    cout << "Introduce el primer número: ";
    cin >> a;
    cout << "Introduce el segundo número: ";
    cin >> b;

    cout << "El MCD de " << a << " y " << b << " es: " << mcd(a, b) << endl;
    return 0;
}