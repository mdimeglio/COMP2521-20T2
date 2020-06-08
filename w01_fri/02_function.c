#include <stdio.h>

void doCalculation(double *x, int *y);

// This program reads in two numbers, a double and an int.
// It prints out the first number divided by 2
// and the second number incremented by 10
// It does not perform any error checking.
int main() {
    double x;
    int y;

    scanf("%lf %d",&x,&y);
    doCalculation(&x, &y);
    printf("%lf %d\n",x,y);

    return 0;
}

void doCalculation(double *a, int *b) {
    *a = *a/2;
    *b = *b + 10;
}


doCalculation:
80: a: 50
84: b: 54


main:
50: x: 3.3
54: y: 12
