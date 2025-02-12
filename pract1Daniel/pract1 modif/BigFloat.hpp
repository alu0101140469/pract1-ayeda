#ifndef BIGFLOAT_HPP
#define BIGFLOAT_HPP

#include "BigUnsigned.hpp"

// Daniel Palenzuela Álvarez alu0101140469
// Modificación

class BigFloat {
    private:
        BigUnsigned number;
        bool isNegative;

    public:
        // Constructores
        BigFloat(float n = 0);
        BigFloat(const BigUnsigned& bigUnsigned);

        // Operadores de entrada y salida
        friend std::ostream& operator<<(std::ostream& out, const BigFloat& num);
        friend std::istream& operator>>(std::istream& in, BigFloat& num);
};

#endif