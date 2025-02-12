#include "BigFloat.hpp"

// Daniel Palenzuela Álvarez alu0101140469

// Constructor desde float
BigFLoat::BigFLoat(float n) : number((n < 0) ? -n : n), isNegative(n < 0) {}

// Constructor desde BigUnsigned
BigFLoat::BigFLoat(const BigUnsigned& bigUnsigned) : number(bigUnsigned), isNegative(false) {}

// Operador de salida
std::ostream& operator<<(std::ostream& out, const BigFLoat& num) {
    if (num.isNegative) out << '-';
    out << num.number;
    return out;
}

// Operador de entrada
std::istream& operator>>(std::istream& in, BigFLoat& num) {
    std::string input;
    in >> input;

    // Verifica si el número es negativo
    num.isNegative = (input[0] == '-');
    
    // Convierte la cadena a BigUnsigned, ignorando el signo si existe
    num.number = BigUnsigned(num.isNegative ? input.substr(1).c_str() : input.c_str());

    return in;
}