#ifndef MAYBE_INT_H
#define MAYBE_INT_H
#include <stdbool.h>

typedef struct _MaybeInt MaybeInt;
struct _MaybeInt {
    bool isJust;
    int value;
};

// constructors
MaybeInt nothing();
MaybeInt just(int value);

// destructors
bool isNothing(MaybeInt r);
bool isJust(MaybeInt r);
int justValue(MaybeInt r);
// can only call justValue if isJust(r)
// is true.

MaybeInt nothingWithValue(int value);

#endif