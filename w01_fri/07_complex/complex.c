// complex.c
#include <stdlib.h>
#include "complex.h"


struct complex {
    double real;
    double imaginary;
};

complex add(complex a, complex b) {
    return NULL;
}
complex multiply(complex a, complex b) {
    return newComplex(
        a->real * b->real - a->imaginary * b->imaginary,
        ///
    );
}
int isEqual(complex a, complex b) {
    return 0;
}

complex newComplex(int real, int imag) {
    complex new = malloc(sizeof(struct complex));
    new->real = real;
    new->imaginary = imag;
    return new;
}
void freeComplex(complex c) {
    free(new);
}