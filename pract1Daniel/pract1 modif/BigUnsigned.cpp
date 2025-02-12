#include "BigUnsigned.hpp"
#include <cstring>

// Daniel Palenzuela Álvarez alu0101140469

// Constructor por defecto y con número
BigUnsigned::BigUnsigned(unsigned n) {
    do {
        digits.push_back(n % 10);
        n /= 10;
    } while (n > 0);
}

// Constructor desde cadena
BigUnsigned::BigUnsigned(const char* str) {
    int len = std::strlen(str);
    for (int i = len - 1; i >= 0; --i) {
        if (str[i] < '0' || str[i] > '9') throw std::invalid_argument("Invalid character");
        digits.push_back(str[i] - '0');
    }
}

// Constructor de copia
BigUnsigned::BigUnsigned(const BigUnsigned& other) : digits(other.digits) {}

// Operador de asignación
BigUnsigned& BigUnsigned::operator=(const BigUnsigned& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

// Operadores de flujo
// Operador de salida
std::ostream& operator<<(std::ostream& out, const BigUnsigned& num) {
    for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it)
        out << static_cast<char>(*it + '0');
    return out;
}

// Operador de entrada
std::istream& operator>>(std::istream& in, BigUnsigned& num) {
    std::string str;
    in >> str;
    num = BigUnsigned(str.c_str());
    return in;
}

// Operadores de comparación
// Operador ==
bool BigUnsigned::operator==(const BigUnsigned& other) const {
    return digits == other.digits;
}

// Operador <
bool operator<(const BigUnsigned& a, const BigUnsigned& b) {
    if (a.digits.size() != b.digits.size())
        return a.digits.size() < b.digits.size();
    for (int i = a.digits.size() - 1; i >= 0; --i) {
        if (a.digits[i] != b.digits[i])
            return a.digits[i] < b.digits[i];
    }
    return false;
}

// Operador >
bool operator>(const BigUnsigned& a, const BigUnsigned& b) {
    return !(a <= b);
}

// Operador <=
bool operator<=(const BigUnsigned& a, const BigUnsigned& b) {
    return (a < b || a == b);
}

// Operador >=
bool operator>=(const BigUnsigned& a, const BigUnsigned& b) {
    return !(a < b);
}

// Operadores aritméticos
// Operador de suma
BigUnsigned operator+(const BigUnsigned& a, const BigUnsigned& b) {
    BigUnsigned result;
    result.digits.clear();
    unsigned carry = 0, sum;
    size_t maxSize = std::max(a.digits.size(), b.digits.size());

    for (size_t i = 0; i < maxSize || carry; ++i) {
        sum = carry;
        if (i < a.digits.size()) sum += a.digits[i];
        if (i < b.digits.size()) sum += b.digits[i];
        carry = sum / 10;
        result.digits.push_back(sum % 10);
    }

    return result;
}

// Operador de resta
BigUnsigned BigUnsigned::operator-(const BigUnsigned& other) const {
    if (*this < other) throw std::underflow_error("Negative result in unsigned subtraction");

    BigUnsigned result = *this;
    size_t len = other.digits.size();
    unsigned borrow = 0;

    for (size_t i = 0; i < len || borrow; ++i) {
        int sub = result.digits[i] - (i < len ? other.digits[i] : 0) - borrow;
        borrow = (sub < 0);
        if (borrow) sub += 10;
        result.digits[i] = sub;
    }

    // Elimina ceros a la izquierda
    while (result.digits.size() > 1 && result.digits.back() == 0)
        result.digits.pop_back();

    return result;
}

// Operador de multiplicación
BigUnsigned BigUnsigned::operator*(const BigUnsigned& other) const {
    BigUnsigned result;
    result.digits.resize(digits.size() + other.digits.size(), 0);

    for (size_t i = 0; i < digits.size(); ++i) {
        unsigned carry = 0;
        for (size_t j = 0; j < other.digits.size() || carry; ++j) {
            unsigned long long mul = result.digits[i + j] +
                                     digits[i] * (j < other.digits.size() ? other.digits[j] : 0) +
                                     carry;
            result.digits[i + j] = mul % 10;
            carry = mul / 10;
        }
    }

    // Elimina ceros a la izquierda
    while (result.digits.size() > 1 && result.digits.back() == 0)
        result.digits.pop_back();

    return result;
}

// Operador de división
BigUnsigned operator/(const BigUnsigned& a, const BigUnsigned& b) {
    if (b == BigUnsigned((unsigned)0)) throw std::domain_error("Division by zero");

    BigUnsigned dividend = a;
    BigUnsigned divisor = b;
    BigUnsigned quotient = BigUnsigned((unsigned)0);

    while (dividend >= divisor) {
        BigUnsigned temp = divisor;
        BigUnsigned factor = BigUnsigned((unsigned)1);
        
        while ((temp + temp) <= dividend) {
            temp = temp + temp; // Multiplica por 2
            factor = factor + factor;
        }

        dividend = dividend - temp;
        quotient = quotient + factor;
    }

    return quotient;
}

// Operador de módulo
BigUnsigned BigUnsigned::operator%(const BigUnsigned& other) const {
    if (other == BigUnsigned(0u)) throw std::domain_error("Modulo by zero");

    BigUnsigned quotient = *this / other;  // Realiza la división entera
    BigUnsigned remainder = *this - (quotient * other);  // Calcula el residuo directamente

    return remainder;
}
