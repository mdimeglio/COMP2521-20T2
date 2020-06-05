#include "Complex.h"
#include <assert.h>

int main() {
    Complex a = createComplex(1, 1);
    Complex b = createComplex(2, 3);
    Complex c = addComplex(a, b);
    Complex d = createComplex(3, 4);
    assert(equals(c, d));
    printf("All tests passed!");
    return 0;
}