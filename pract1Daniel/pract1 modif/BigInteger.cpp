#include "BigInteger.hpp"

// Daniel Palenzuela Álvarez alu0101140469

// Constructor desde int
BigInteger::BigInteger(int n) : number((n < 0) ? -n : n), isNegative(n < 0) {}

// Constructor desde BigUnsigned
BigInteger::BigInteger(const BigUnsigned& bigUnsigned) : number(bigUnsigned), isNegative(false) {}

// Operador de salida
std::ostream& operator<<(std::ostream& out, const BigInteger& num) {
    if (num.isNegative) out << '-';
    out << num.number;
    return out;
}

// Operador de entrada
std::istream& operator>>(std::istream& in, BigInteger& num) {
    std::string input;
    in >> input;

    // Verifica si el número es negativo
    num.isNegative = (input[0] == '-');
    
    // Convierte la cadena a BigUnsigned, ignorando el signo si existe
    num.number = BigUnsigned(num.isNegative ? input.substr(1).c_str() : input.c_str());

    return in;
}

// Algoritmo de Euclides para calcular el MCD
BigInteger mcd(const BigInteger& a, const BigInteger& b) {
    BigUnsigned x = a.number, y = b.number;
    while (!(y == BigUnsigned((unsigned)0))) {
        BigUnsigned temp = y;
        y = x % y;
        x = temp;
    }
    return BigInteger(x);
}