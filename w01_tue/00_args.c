/*
Consider a program called myprog which is invoked as:
```shell
./myprog  hello there,  'John Shepherd'  >  myFile
```
(a) What are the values of argc and argv?
(b) Where would the statement printf("%s", argv[1]) place its output?
(c) Where would the statement ch = getchar(); get its input?
*/
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: \"%s\"\n", i, argv[i]);
    }
}
