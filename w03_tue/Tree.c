// By Matthew Di Meglio
#include <stdlib.h>
#include <stdbool.h>
#include "Tree.h"
#include "EitherIntInt.h"

struct branch {
	int key;
	Tree left;
	Tree right;
};

Tree nonEmptyTree(int key, Tree left, Tree right) {
    Tree t = malloc(sizeof(struct branch));
    t->key = key;
    t->left = left;
    t->right = right;
    return t;
}

Tree emptyTree() {
    return NULL;
}

bool isLeaf(Tree t) {
    return t == NULL;
}

void freeTree(Tree t) {
    if (t != NULL) {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

int countNodes(Tree t) {
    if (isLeaf(t)) {
        return 0;
    } else {
        return 1 + countNodes(t->left)
                 + countNodes(t->right);
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int depth(Tree t) {
    if (isLeaf(t)) {
        return 0;
    } else {
        return 1 + max(depth(t->left), depth(t->right));
    }
}

// Returns depth of node with key
MaybeInt nodeDepth(Tree t, int key) {
    if (isLeaf(t)) {
        return nothing();
    } else {
        if (key == t->key) {
            return just(1);
        } else {
            MaybeInt maybeDepth;
            if (key < t->key) {
                maybeDepth = nodeDepth(t->left, key);
            } else {
                maybeDepth = nodeDepth(t->right, key);
            }

            if (isNothing(maybeDepth)) {
                return nothing();
            } else {
                return just(1 + justValue(maybeDepth));
            }
        }
    }
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