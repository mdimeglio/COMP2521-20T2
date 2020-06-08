#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef struct _BSTNode BSTNode;
typedef BSTNode *BSTree;

struct _BSTNode {
	int key;
	BSTree left;
	BSTree right;
};

struct _Successor {
    int type;
    int successorKey;
};
typedef struct _Successor Successor;

#define KEY_NOT_FOUND 0
#define SUCCESSOR_NOT_FOUND 1
#define SUCCESSOR_FOUND 2

Successor keyNotFound();
Successor successorNotFound();
Successor successorFound(int successorKey);

BSTree tree(int key, BSTree left, BSTree right);
void freeTree(BSTree t);

void testIsHeightBalanced();
int isHeightBalanced(BSTree t);

void testIsSymmetric();
int isSymmetric(BSTree t);

void testIsSearchTree();
int isSearchTree(BSTree t);

void testInOrderSuccessor();
Successor inOrderSuccessor(BSTree t, int key);

int main() {
    testIsHeightBalanced();
    testIsSymmetric();
    testIsSearchTree();
    testInOrderSuccessor();
    printf("All tests passed!\n");
    return 0;
}

/////////////////////
// HEIGHT BALANCED //
/////////////////////

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

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int abs(int a) {
    return max(a, -a);
}

int height(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + max(height(t->left), height(t->right));
    }
}

int isHeightBalanced(BSTree t) {
    return
        t == NULL ||
        (
            isHeightBalanced(t->left) &&
            isHeightBalanced(t->right) &&
            abs(height(t->left) - height(t->right)) <= 1
        );
}


/////////////////////
// SYMMETRIC       //
/////////////////////

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

    t =
        tree(
            1,
            tree(
                2,
                tree(
                    3,
                    NULL,
                    NULL
                ),
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            tree (
                2,
                tree(
                    4,
                    NULL,
                    NULL
                ),
                tree(
                    3,
                    NULL,
                    NULL
                )
            )
        );
    assert(isSymmetric(t));
    freeTree(t);

        t =
        tree(
            1,
            tree(
                2,
                tree(
                    3,
                    NULL,
                    NULL
                ),
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            tree (
                2,
                tree(
                    3,
                    NULL,
                    NULL
                ),
                tree(
                    4,
                    NULL,
                    NULL
                )
            )
        );
    assert(!isSymmetric(t));
    freeTree(t);
}

int isMirror(BSTree s, BSTree t) {
    return
        (s == NULL && t == NULL) ||
        (
            s != NULL &&
            t != NULL &&
            s->key == t->key &&
            isMirror(s->left, t->right) &&
            isMirror(s->right, t->left)
        );
}

int isSymmetric(BSTree t) {
    return t == NULL || isMirror(t->left, t->right);
    // return isMirror(t, t);
}


/////////////////////
// SEARCH TREE     //
/////////////////////

void testIsSearchTree() {
    assert(isSearchTree(NULL));

    BSTree t;

    t =
        tree(
            20,
            tree(
                10,
                tree(
                    5,
                    NULL,
                    NULL
                ),
                NULL
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
    assert(isSearchTree(t));
    freeTree(t);

    t =
        tree(
            5,
            tree(
                10,
                NULL,
                NULL
            ),
            NULL
        );
    assert(!isSearchTree(t));
    freeTree(t);

    t =
        tree(
            5,
            NULL,
            tree(
                2,
                NULL,
                NULL
            )
        );
    assert(!isSearchTree(t));
    freeTree(t);

    t =
        tree(
            5,
            tree(
                5,
                NULL,
                NULL
            ),
            NULL
        );
    assert(!isSearchTree(t));
    freeTree(t);

    t =
        tree(
            20,
            tree(
                10,
                NULL,
                tree(
                    25,
                    NULL,
                    NULL
                )
            ),
            NULL
        );
    assert(!isSearchTree(t));
    freeTree(t);

    t = 
        tree(
            30,
            tree(
                10,
                NULL,
                tree(
                    20,
                    tree(
                        5,
                        NULL,
                        NULL
                    ),
                    NULL
                )
            ),
            NULL
        );
    assert(!isSearchTree(t));
    freeTree(t);
}

int maxKey(BSTree t) {
    if (t == NULL) {
        return INT_MIN;
    } else {
        //return max(max(maxKey(t->left), maxKey(t->right)), t->key);
        return max(t->key, maxKey(t->right)); // Assuming we already know that t is a search tree
    }
}

int minKey(BSTree t) {
    if (t == NULL) {
        return INT_MAX;
    } else {
        return min(t->key, minKey(t->left)); // Assuming we already know that t is a search tree
        //return min(min(minKey(t->left), minKey(t->right)), t->key);
    }
}

int isSearchTree(BSTree t) {
    return
        t == NULL ||
        (
            isSearchTree(t->left) &&
            isSearchTree(t->right) &&
            maxKey(t->left) < t->key &&
            minKey(t->right) > t->key
        );
}


///////////////////////
// INORDER SUCCESSOR //
///////////////////////

void testInOrderSuccessor() {
    BSTree t;
    Successor s;

    s = inOrderSuccessor(NULL, 3);
    assert(s.type == KEY_NOT_FOUND);

    t = tree(3, NULL, NULL);
    s = inOrderSuccessor(t, 3);
    assert(s.type == SUCCESSOR_NOT_FOUND);
    freeTree(t);

    t = tree(3, NULL, tree(5, NULL, NULL));
    s = inOrderSuccessor(t, 3);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 5);
    freeTree(t);

    t = tree(3, NULL, tree(5, tree(4, NULL, NULL), NULL));

    s = inOrderSuccessor(t, 3);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 4);

    s = inOrderSuccessor(t, 4);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 5);

    freeTree(t);

    t = tree(20, tree(10, tree(5, NULL, NULL), tree(15, NULL, NULL)), tree(30, NULL, NULL));
    s = inOrderSuccessor(t, 15);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 20);

    s = inOrderSuccessor(t, 10);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 15);

    s = inOrderSuccessor(t, 13);
    assert(s.type == KEY_NOT_FOUND);
    
    s = inOrderSuccessor(t, 30);
    assert(s.type == SUCCESSOR_NOT_FOUND);

    freeTree(t);
}

Successor inOrderSuccessor(BSTree t, int key) {
    if (t == NULL) {
        return keyNotFound();
    } else {
        if (key == t->key) {
            if (t->right != NULL) {
                return successorFound(minKey(t->right));
            } else {
                return successorNotFound();
            }
        } else if (key < t->key) {
            Successor s = inOrderSuccessor(t->left, key);
            if (s.type == SUCCESSOR_NOT_FOUND) {
                return successorFound(t->key);
            } else {
                return s;
            }
        } else { // key > t->key
            return inOrderSuccessor(t->right, key);
        }
    }
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

Successor keyNotFound() {
    return (Successor) {KEY_NOT_FOUND, 0};
}
Successor successorNotFound() {
    return (Successor) {SUCCESSOR_NOT_FOUND, 0};
}
Successor successorFound(int successorKey) {
    return (Successor) {SUCCESSOR_FOUND, successorKey};
}