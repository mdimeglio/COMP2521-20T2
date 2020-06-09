# Primitive operations
The C statement
```C
y = x + 3;
```
is compiled to the following three (pseudo) assembly instructions:
```
load  R1, x
add   R1, R1, 3
store R1, y
```

(a) Which instructions might the following C code compile to?
```C
a = b + c * d;
```

The following C code
```C
int i = 0;
while (i < n) {
    i++;
}
```
translates to the following (pseudo) assembly code:
```
    load        R0, 0
    load        R1, n
WHILE:
    jump_if_>=  R0, R1, ENDWHILE
    add         R0, R0, 1
    jump        WHILE
END_WHILE:
```

(b) If n = 2, how many instructions will be executed?

(c) What is the number of executed instructions as a function of n?

(d) What is the time complexity of this function?

