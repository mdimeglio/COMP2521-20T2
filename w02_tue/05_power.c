#include <stdio.h>
#include <assert.h>

int power(int x, unsigned int n);

int main() {
    assert(power(2, 0) == 1);
    assert(power(2, 1) == 2);
    assert(power(2, 2) == 4);
    assert(power(0, 2) == 0);
    assert(power(3, 4) == 81);

    printf("All tests passed!\n");
    return 0;
}

int pow(int x, unsigned int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * x;
    }
    return res;
}













/*
int pow(int x, unsigned int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * x;
    }
    return res;
}

int power(int x, unsigned int n) {
    if (n == 0) {
        return 1;
    } else {
        int xToHalfN = power(x, n/2);
        return xToHalfN * xToHalfN *
            ((n % 2 == 0) ? 1 : x);
    }
}*/