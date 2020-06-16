#include "EitherIntInt.h"

EitherIntInt left(int value) {
    EitherIntInt e;
    e.isLeft = true;
    e.value = value;
    return e;
}

EitherIntInt right(int value) {
    EitherIntInt e;
    e.isLeft = false;
    e.value = value;
    return e;
}

bool isLeft(EitherIntInt r) {
    return r.isLeft;
}

bool isRight(EitherIntInt r) {
    return !r.isLeft;
}

int value(EitherIntInt r) {
    return r.value;
}