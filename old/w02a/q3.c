#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int evaluatePolynomial(int degree, int *coefficients, int parameter);

int main() {
    int p1[] = {3, 5, 2};
    assert(evaluatePolynomial(2, p1, 1) == 10);
    assert(evaluatePolynomial(2, p1, 2) == 21);

    int p2[1] = {3};
    assert(evaluatePolynomial(0, p2, 4) == 3);

    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

// Computes x^n
int power(int n, int x) {
    int pow = 1;
    for (int i = 0; i < n; i++) {
        pow *= x;
    }
    return pow;
}

int evaluatePolynomial(int n, int *a, int x) {
    int val = 0;
    int pow = 1;
    for(int i = 0; i <= n; i++) {
        val += pow * a[i];
        pow *= x;
    }
    return val;
}

