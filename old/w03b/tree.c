#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _BSTNode BSTNode;
typedef BSTNode *BSTree;

struct _BSTNode {
	int key;
	BSTree left;
	BSTree right;
};

struct _SearchResult {
    int isSuccess;
    int result;
};
typedef struct _SearchResult SearchResult;

BSTree tree(int key, BSTree left, BSTree right);
void freeTree(BSTree t);

void testCountNodes();
int countNodes(BSTree t);

void testDepth();
int depth(BSTree t);

SearchResult fail();
SearchResult success(int result);

void testNodeDepth();
SearchResult nodeDepth(BSTree t, int key);

void testNthSmallest();
SearchResult nthSmallest(BSTree t, int n);

void testInOrderSuccessor();
SearchResult inOrderSuccessor(BSTree t, int key);

int main() {
    testCountNodes();
    testNodeDepth();
    testDepth();
    testNthSmallest();
    testInOrderSuccessor();
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
        return 1 + countNodes(t->left) + countNodes(t->right);
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

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int depth(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return max(depth(t->left), depth(t->right)) + 1;
    }
}


SearchResult fail() {
    return (SearchResult) {0, 0};
}

SearchResult failWithResult(int result) {
    return (SearchResult) {0, result};
}

SearchResult success(int result) {
    return (SearchResult) {1, result};
}

int isFail(SearchResult r) {
    return !r.isSuccess;
}

int isSuccess(SearchResult r, int expectedResult) {
    return r.isSuccess && r.result == expectedResult;
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

    assert(isSuccess(nodeDepth(t, 3), 2));
    assert(isSuccess(nodeDepth(t, 5), 1));
    assert(isFail(nodeDepth(t, 29)));
    assert(isFail(nodeDepth(t, -2)));

    freeTree(t);
}

// Returns depth of node with key
SearchResult nodeDepth(BSTree t, int key) {
    if (t == NULL) {
        return fail();
    } else if (key == t->key) {
        return success(1);
    } else {
        SearchResult r;
        if (key < t->key) {
            r = nodeDepth(t->left, key);
        } else {
            r = nodeDepth(t->right, key);
        }

        if (isFail(r)) {
            return r;
        } else {
            r.result++;
            return r;
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

    assert(isSuccess(nthSmallest(t, 1), 3));
    assert(isSuccess(nthSmallest(t, 2), 4));
    assert(isSuccess(nthSmallest(t, 3), 5));
    assert(isFail(nthSmallest(t, 5)));

    freeTree(t);
}

// 1 -> smallest
// 2 -> second smallest
// etc.
SearchResult nthSmallest(BSTree t, int n) {
    if (t == NULL) {
        return failWithResult(0);
    } else {
        SearchResult leftResult = nthSmallest(t->left, n);
        if (isFail(leftResult)) {
            int leftSize = leftResult.result;
            if (leftSize == n - 1) {
                return success(t->key);
            } else {
                SearchResult rightResult = nthSmallest(t->right, n - leftSize - 1);
                if (isFail(rightResult)) {
                    rightResult.result += leftSize + 1;
                    return rightResult;
                } else {
                    return rightResult;
                }
            }
        } else {
            return leftResult;
        }
    }
}

void testInOrderSuccessor() {

}

SearchResult inOrderSuccessor(BSTree t, int key) {
    return fail();
}