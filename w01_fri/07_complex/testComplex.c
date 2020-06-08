// testComplex.c
#include <stdio.h>
#include <assert.h>
#include "complex.h"

int main() {
    complex a = newComplex(1, 2);
    complex b = newComplex(3, 4);
    complex sum = add(a, b);
    complex expected = newComplex(4, 6);
    assert(isEqual(sum, expected));
    printf("All tests passed!\n");
    freeComplex(a);
    freeComplex(b);
    freeComplex(sum);
    freeComplex(expected);
    return 0;
}