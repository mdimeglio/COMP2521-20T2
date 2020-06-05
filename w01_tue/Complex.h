

typedef struct complex * Complex;

Complex addComplex(Complex a, Complex b);
Complex multComplex(Complex a, Complex b);
int equals(Complex a, Complex b)


Complex createComplex(int real, int imaginary);
void freeComplex(Complex z);