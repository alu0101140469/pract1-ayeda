#ifndef BIGUNSIGNED_HPP
#define BIGUNSIGNED_HPP

#include <iostream>
#include <vector>
#include <string>

// Daniel Palenzuela Álvarez alu0101140469

class BigUnsigned {
private:
    std::vector<unsigned char> digits; // Almacena los dígitos en orden inverso (Little Endian)

public:
    // Constructores
    BigUnsigned(unsigned n = 0);
    BigUnsigned(const char* str);
    BigUnsigned(const BigUnsigned& other); // Constructor de copia

    // Operador de asignación
    BigUnsigned& operator=(const BigUnsigned& other);

    // Operadores de flujo
    friend std::ostream& operator<<(std::ostream& out, const BigUnsigned& num);
    friend std::istream& operator>>(std::istream& in, BigUnsigned& num);

    // Operadores de comparación
    bool operator==(const BigUnsigned& other) const;
    friend bool operator<(const BigUnsigned& a, const BigUnsigned& b);
    friend bool operator>(const BigUnsigned& a, const BigUnsigned& b);
    friend bool operator<=(const BigUnsigned& a, const BigUnsigned& b);
    friend bool operator>=(const BigUnsigned& a, const BigUnsigned& b);

    // Operadores de incremento/decremento
    BigUnsigned& operator++();    // Pre-incremento
    BigUnsigned operator++(int);  // Post-incremento
    BigUnsigned& operator--();    // Pre-decremento
    BigUnsigned operator--(int);  // Post-decremento

    // Operadores aritméticos
    friend BigUnsigned operator+(const BigUnsigned& a, const BigUnsigned& b);
    BigUnsigned operator-(const BigUnsigned& other) const;
    BigUnsigned operator*(const BigUnsigned& other) const;
    friend BigUnsigned operator/(const BigUnsigned& a, const BigUnsigned& b);
    BigUnsigned operator%(const BigUnsigned& other) const;
};

#endif