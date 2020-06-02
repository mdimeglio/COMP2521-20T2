Consider the following code fragment:

```C
void doCalculation (double x, int y);

// This program reads in two numbers, a double and an int.
// It prints out the first number divided by 2
// and the second number incremented by 10
// It does not perform any error checking.
int main (int argc, char * argv[]){
    double x;
    int y;

    scanf("%lf %d",&x,&y);
    doCalculation(x,y);
    printf("%lf %d\n",x,y);

    return EXIT_SUCCESS;
}

void doCalculation (double x, int y){
    x = x/2;
    y = y + 10;
}
```

(a) Explain what is wrong with this program and why it does not work as
expected from the comment.

(b) Write a different prototype for the function doCalculation to
successfully change the values in main.

(c) Implement this different doCalculation (ie write the code for it).

(d) How would you now call the function within the main function?
