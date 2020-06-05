#include <stdio.h>

void doCalculation(double x, int y);

// This program reads in two numbers, a double and an int.
// It prints out the first number divided by 2
// and the second number incremented by 10
// It does not perform any error checking.
int main() {
    double x;
    int y;

    scanf("%lf %d",&x,&y);
    doCalculation(x, y);
    printf("%lf %d\n",x,y);

    return 0;
}

void doCalculation(double x, int y) {
    x = x/2;
    y = y + 10;
}


100: "%lf %d"

doCalculation:



main:
50: x: 6.6
54: y: 2
