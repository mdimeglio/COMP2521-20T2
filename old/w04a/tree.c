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
SearchResult fail();
SearchResult failWithResult(int result);
SearchResult success(int result);
int isFail(SearchResult r);
int isSuccess(SearchResult r, int expectedResult);

void testIsHeightBalanced();
int isHeightBalanced(BSTree t);

void testIsSymmetric();
int isSymmetric(BSTree t);

void testIsSearchTree();
int isSearchTree(BSTree t);

void printTopView(BSTree t);

void testInOrderSuccessor();
SearchResult inOrderSuccessor(BSTree t, int key);


int main() {
    testIsHeightBalanced();
    testIsSymmetric();
    testInOrderSuccessor();
    printf("All tests passed!\n");
    return 0;
}


void testIsHeightBalanced() {
    assert(isHeightBalanced(NULL));

    BSTree t =
        tree(
            2,
            tree(
                1,
                NULL,
                NULL
            ),
            tree(
                3,
                NULL,
                NULL
            )
        );
    assert(isHeightBalanced(t));
    freeTree(t);

    t =
        tree(
            2,
            tree(
                1,
                NULL,
                NULL
            ),
            NULL
        );
    assert(isHeightBalanced(t));
    freeTree(t);

    t =
        tree(
            2,
            NULL,
            tree(
                3,
                NULL,
                NULL
            )
        );
    assert(isHeightBalanced(t));
    freeTree(t);

    t = 
        tree(
            3,
            tree(
                2,
                tree(
                    1,
                    NULL,
                    NULL
                ),
                NULL
            ),
            NULL
        );
    assert(!isHeightBalanced(t));
    freeTree(t);

    t = 
        tree(
            20,
            tree(
                10,
                NULL,
                tree(
                    15,
                    tree(
                        12,
                        NULL,
                        NULL
                    ),
                    NULL
                )
            ),
            tree(
                30,
                tree(
                    25,
                    NULL,
                    tree(
                        27,
                        NULL,
                        NULL
                    )
                ),
                NULL
            )
        );

    assert(!isHeightBalanced(t));
    freeTree(t);
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int abs(int a) {
    return max(a, -a);
}


// If t is height balanced, then return height
// else return -1
int isHeightBalancedRec(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        int left = isHeightBalancedRec(t->left);
        int right = isHeightBalancedRec(t->right);
        if (left != -1 && right != -1 && abs(left - right) <= 1) {
            return max(left, right) + 1;
        } else {
            return -1;
        }
    }
}

// SearchResult isHeightBalancedRec(BSTree t) {
//     if (t == NULL) {
//         return success(0);
//     } else {
//         int left = isHeightBalancedRec(t->left);
//         int right = isHeightBalancedRec(t->right);
//         if (!isFail(left) && !isFail(right) && abs(left.result - right.result) <= 1) {
//             return success(max(left.result, right.result) + 1);
//         } else {
//             return fail();
//         }
//     }
// }

int isHeightBalanced(BSTree t) {
    return isHeightBalancedRec(t) != -1;
}

void testIsSymmetric() {
    assert(isSymmetric(NULL));

    BSTree t =
        tree(1,
            tree(
                2,
                NULL,
                NULL
            ),
            tree(
                2,
                NULL,
                NULL
            )
        );
    assert(isSymmetric(t));
    freeTree(t);

    t =
        tree(1,
            tree(2,
                NULL,
                NULL),
            NULL);
    assert(!isSymmetric(t));
    freeTree(t);
}


int isMirror(BSTree s, BSTree t) {
    return
        (s == NULL && t == NULL) ||
        (
            s != NULL &&
            t != NULL &&
            isMirror(s->left, t->right) &&
            isMirror(s->right, t->left) &&
            s->key == t->key
        );
}

int isSymmetric(BSTree t) {
    return t == NULL || isMirror(t->left, t->right);
}

void testIsSearchTree();
int isSearchTree(BSTree t);

void printTopView(BSTree t);


void testInOrderSuccessor() {

}

SearchResult inOrderSuccessor(BSTree t, int key) {
    return fail();
}


// Extra functions

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


