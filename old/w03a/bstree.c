#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NOT_FOUND -1

typedef struct _BSTNode BSTNode;
typedef BSTNode *BSTree;

struct _BSTNode {
	int key;
	BSTree left;
	BSTree right;
};

BSTree tree(int key, BSTree left, BSTree right);
void freeTree(BSTree t);

void testCountNodes();
int countNodes(BSTree t);


void testNodeDepth();
int nodeDepth(BSTree t, int key);

void testDepth();
int depth(BSTree t);

void testNthSmallest();
int nthSmallest(BSTree t, int n);

int inOrderSuccessor(BSTree t, int key);

int main() {
    testCountNodes();
    testNodeDepth();
    testDepth();
    testNthSmallest();
    printf("All tests passed!\n");
    return 0;
}

BSTree tree(int key, BSTree left, BSTree right) {
    BSTree t = malloc(sizeof(BSTNode));
    t->key = key;
    t->left = left;
    t->right = right;
    return t;
}

void freeTree(BSTree t) {
    if (t != NULL) {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

void testCountNodes() {
    BSTree t =
        tree(
            5,
            tree(
                3,
                NULL,
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    assert(countNodes(t) == 3);
    assert(countNodes(NULL) == 0);

    freeTree(t);
}

int countNodes(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return countNodes(t->left) + countNodes(t->right) + 1;
    }
}


void testNodeDepth() {
    BSTree t =
        tree(
            5,
            tree(
                3,
                NULL,
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    assert(nodeDepth(t, 3) == 2);
    assert(nodeDepth(t, 5) == 1);
    assert(nodeDepth(t, 29) == NOT_FOUND);
    assert(nodeDepth(t, -2) == NOT_FOUND);

    freeTree(t);
}

// Returns depth of node with key
// if it exists, else NOT_FOUND
int nodeDepth(BSTree t, int key) {
    if (t == NULL) {
        return NOT_FOUND;
    } else if (key == t->key) {
        return 1;
    } else {
        int depth;
        if (key < t->key) {
            depth = nodeDepth(t->left, key);
        } else {
            depth = nodeDepth(t->right, key);
        }

        if (depth == NOT_FOUND) {
            return NOT_FOUND;
        } else {
            return 1 + depth;
        }
    }
}

void testDepth() {
    BSTree t =
        tree(
            5,
            tree(
                3,
                NULL,
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    assert(depth(t) == 3);
    assert(depth(t->left) == 2);
    assert(depth(NULL) == 0);

    freeTree(t);
}

int depth(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        int left = depth(t->left);
        int right = depth(t->right);
        if (left > right) {
            return 1 + left;
        } else {
            return 1 + right;
        }
    }
}

void testNthSmallest() {
    BSTree t =
        tree(
            5,
            tree(
                3,
                NULL,
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    assert(nthSmallest(t, 1) == 3);
    assert(nthSmallest(t, 2) == 4);
    assert(nthSmallest(t, 3) == 5);
    assert(nthSmallest(t, 5) == NOT_FOUND);

    freeTree(t);
}

// 1 -> smallest
// 2 -> second smallest
// etc.
// assume all keys >= 0
// return NOT_FOUND if n is too big


int recNthSmallest(BSTree t, int n, int *size) {
    if (t == NULL) {
        *size = 0;
        return NOT_FOUND;
    } else {
        int leftSize;
        int left = recNthSmallest(t->left, n, &leftSize);

        if (left == NOT_FOUND) {
            if (leftSize == n - 1) {
                return t->key;
            } else {
                int rightSize;
                int right = recNthSmallest(t->right, n - leftSize - 1, &rightSize);
                *size = leftSize + rightSize + 1;
                return right;
            }
        } else {
            return left;
        }
    }
}

int nthSmallest(BSTree t, int n) {
    int size;
    return recNthSmallest(t, n, &size);
}

int inOrderSuccessor(BSTree t, int key);