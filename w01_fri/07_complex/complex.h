// complex.h
typedef struct complex *complex;

complex add(complex a, complex b);
complex multiply(complex a, complex b);
int isEqual(complex a, complex b);

complex newComplex(int real, int imag);
void freeComplex(complex c);