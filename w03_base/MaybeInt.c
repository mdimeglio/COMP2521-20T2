// By Matthew Di Meglio
#include <assert.h>
#include "MaybeInt.h"

MaybeInt nothing() {
    MaybeInt m;
    m.isJust = false;
    m.value  = 0;
    return m;
}

MaybeInt just(int value) {
    MaybeInt m;
    m.isJust = true;
    m.value  = value;
    return m;
}

bool isNothing(MaybeInt r) {
    return !r.isJust;
}

bool isJust(MaybeInt r) {
    return r.isJust;
}

int justValue(MaybeInt r) {
    assert(isJust(r));
    return r.value;
}

MaybeInt nothingWithValue(int value) {
    return (MaybeInt) {0, value};
}