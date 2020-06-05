#include "Complex.h"

struct complex {
    int real;
    int imag;
}

// modulus * e^{i * argment}

Complex multComplex(Complex a, Complex b) {
    return newComplex(
        a->modulus * b->modulus,
        a->argument + b->argument;
    )
}

Complex addComplex(Complex a, Complex b);