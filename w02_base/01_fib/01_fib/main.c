#include <stdio.h>
#include <assert.h>
// 1 1 2 3 5 8
// fib(n) = { 1 if n = 1 or 2, fib(n-1) + fib(n-2) otherwise
int fib(int n);

int main() {
    int x = fib(3);
    printf("%d\n", x);
    return 0;
}

int fib(int n) {
    assert(n > 0);
    
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}
