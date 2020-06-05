Consider the following code fragment:

```C
#include <stdio.h>
#include <stdlib.h>

void doCalculation (double x, int y);

// This program reads in two numbers, a double and an int.
// It prints out the first number divided by 2
// and the second number incremented by 10
// It does not perform any error checking.
int main (int argc, char * argv[]){
    double x;
    int y;

    scanf("%lf %d", &x, &y);
    doCalculation(&x, &y);
    printf("%lf %d\n", x, y);

    return 0;
}

void doCalculation (double *a, int *b){
    *a = *a/2;
    *b = *b + 10;
}

DoCalculation
a: 01
b:

Main:
01 x = 1.9
02 y = 15

```

(a) Explain what is wrong with this program and why it does not work as
expected from the comment.

(b) Write a different prototype for the function doCalculation to
successfully change the values in main.

(c) Implement this different doCalculation (ie write the code for it).

(d) How would you now call the function within the main function?
