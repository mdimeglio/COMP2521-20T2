#include <stdio.h>

int h(int z);
int g(int *x, int y, int z);
int f(int *x, int y, int *z);

int main(int argc, char *argv[]) {
  int x = 1;
  int y = 2;
  int z = 3;

  x = f(&z, x, &y);

  printf("%d %d %d\n",x,y,z);

  return 0;
}

int h(int z) {
    return z*z;
}

int g(int *x, int y, int z) {
   z = *x;
   *x = y;
   y = h(z);
   return z+y;
}

int f(int *x, int y, int *z) {
   return g(&y, *z, *x);
}