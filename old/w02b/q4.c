#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct sparseVectorNode {
    int index;
    int value;
    struct sparseVectorNode *next;
};

typedef struct sparseVectorNode *SparseVector;

SparseVector cons(int index, int value, SparseVector next);
SparseVector sum(SparseVector a, SparseVector b);
SparseVector copy(SparseVector v);
int equals(SparseVector a, SparseVector b);
void freeVector(SparseVector v);

void print(SparseVector v) {
    if (v == NULL) {
        printf("X\n");
    } else {
        printf("[index: %d, value: %d] ->", v->index, v->value);
        print(v->next);
    }
}

int main() {
    SparseVector a = cons(99, 3, cons(23, 1, cons(1, 2, NULL)));
    SparseVector b = cons(97, 1, cons(23, 2, NULL));
    SparseVector s1 = sum(a, b);
    SparseVector s2 = cons(99, 3, cons(97, 1, cons(23, 3, cons(1, 2, NULL))));
    // print(s1);
    // print(s2);
    
    assert(equals(s1, s2));
    
    freeVector(a);
    freeVector(b);
    freeVector(s1);
    freeVector(s2);

    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}


SparseVector cons(int index, int value, SparseVector next) {
    SparseVector newNode = malloc(sizeof(struct sparseVectorNode));
    newNode->index = index;
    newNode->value = value;
    newNode->next = next;
    return newNode;
}

SparseVector copy(SparseVector v) {
    if (v == NULL) {
        return NULL;
    } else {
        return cons(v->index, v->value, copy(v->next));
    }
}

void freeVector(SparseVector v) {
    if (v != NULL) {
        freeVector(v->next);
        free(v);
    }
}

int equals(SparseVector a, SparseVector b) {
    return (a == NULL && b == NULL) ||
            (a != NULL
            && b != NULL
            && a->index == b->index
            && a->value == b->value
            && equals(a->next, b->next));
}


SparseVector sum(SparseVector a, SparseVector b) {
    if (a == NULL) {
        return copy(b);
    } else if (b == NULL) {
        return copy(a);
    } else if (a->index > b->index) {
        return cons(a->index, a->value, sum(a->next, b));
    } else if (a->index < b->index) {
        return cons(b->index, b->value, sum(a, b->next));
    } else {
        return cons(a->index, a->value + b->value, sum(a->next, b->next));
    }
}