#include <stdio.h>
#include <assert.h>

int factorial(int n);

int main(int argc, char *argv[]) {
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(2) == 2);
    assert(factorial(3) == 6);
    printf("All tests passed!\n");
    return 0;
}

int factorial(int n) {
    // TODO
    return 0;
}