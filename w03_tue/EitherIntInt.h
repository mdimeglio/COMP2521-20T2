// By Matthew Di Meglio
#ifndef EITHER_INT_INT_H
#define EITHER_INT_INT_H
#include <stdbool.h>

typedef struct _EitherIntInt EitherIntInt;
struct _EitherIntInt {
    bool isLeft;
    int value;
};

// constructors
EitherIntInt left(int value);
EitherIntInt right(int value);

// destructors
bool isLeft(EitherIntInt r);
bool isRight(EitherIntInt r);
int value(EitherIntInt r);

#endif