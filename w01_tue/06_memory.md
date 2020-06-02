# Week 3 - Question 2 - Memory and Pointers

Below are the hexadecimal contents of memory locations `F000`..`F00F` on a 32 bit little endian computer currently running a program:

Address | Data
-|-
F000 | 04
F001 | F0
F002 | 00
F003 | 00
F004 | 0C
F005 | F0
F006 | 00
F007 | 00
F008 | F0
F009 | F1
F00A | FF
F00B | FF
F00C | 42
F00D | 79
F00E | 65
F00F | 00

## Part 1 - Revision
The currently running program was written in C and includes the following four (consecutive) lines of printfs involving an `unsigned int m`

```C
printf ("%p\n", &m);
printf ("In hex is %x\n", m);
int n = m;
printf ("In decimal is %d\n", n);
```

The first printf prints out `0xf008`. What do the other two printfs print out?

## Part 2 - Pointers

The currently running program also includes the following seven (consecutive) lines of printfs involving an `int *x` and an `int **y`

```C
printf ("%p\n", &x);
printf ("%p\n", &y);
printf ("  x == %p\n", x);
printf (" *x == %x\n", *x);
printf ("  y == %p\n", y);
printf (" *y == %p\n", *y);
printf ("**y == %d\n", **y);
```

The first printf prints out `0xf004` and the second printf prints out `0xf000`. What do the other two printfs print out?