#include <stdio.h>
#include <stdlib.h>


struct sparseVectorNode {
    int index;
    int value;
    struct sparseVectorNode *next;
}

typedef struct sparseVectorNode *SparseVector;

SparseVector append(int index, int value, SparseVector next) {
    SparseVector newNode = malloc();
}

SparseVector sum(SparseVector a, SparseVector b) {
    if (a == NULL) {

    } else if (b == NULL) {

    } else if (a->index < b->index) {

    } else if (a->index > b->index) {

    } else {

    }
}