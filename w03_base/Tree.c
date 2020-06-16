
#include <stdlib.h>
#include "Tree.h"
#include "EitherIntInt.h"

struct branch {
	int key;
	Tree left;
	Tree right;
};

Tree branch(int key, Tree left, Tree right) {
    Tree t = malloc(sizeof(struct branch));
    t->key = key;
    t->left = left;
    t->right = right;
    return t;
}

Tree leaf() {
    return NULL;
}

void freeTree(Tree t) {
    if (t != NULL) {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

int countNodes(Tree t) {
    // TODO
    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int depth(Tree t) {
    // TODO
    return 0;
}

// Returns depth of node with key
MaybeInt nodeDepth(Tree t, int key) {
    // TODO
    return nothing();
}

// if n > size of t
//  then returns left(size of t)
//  else returns right(nth key in t)
EitherIntInt nthSmallestRec(Tree t, int n) {
    // TODO
    return left(0);
}

// 1 -> smallest
// 2 -> second smallest
// etc.
MaybeInt nthSmallest(Tree t, int n) {
    EitherIntInt e = nthSmallestRec(t, n);
    if (isRight(e)) {
        return just(value(e));
    } else {
        return nothing();
    }
}