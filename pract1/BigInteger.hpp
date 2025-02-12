#ifndef BIGINTEGER_HPP
#define BIGINTEGER_HPP

#include "BigUnsigned.hpp"

class BigInteger {
private:
    BigUnsigned number;
    bool isNegative;

public:
    // Constructores
    BigInteger(int n = 0);
    BigInteger(const BigUnsigned& bigUnsigned);

    // Operadores de entrada y salida
    friend std::ostream& operator<<(std::ostream& out, const BigInteger& num);
    friend std::istream& operator>>(std::istream& in, BigInteger& num);

    // Cálculo del MCD
    friend BigInteger mcd(const BigInteger& a, const BigInteger& b);
};

#endif