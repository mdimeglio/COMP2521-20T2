#include <stdlib.h>
#include <stdio.h>

typedef struct list *List;
struct list {
    int head;
    List tail;
};

int isEmpty(List l);
List nonEmpty(int head, List tail);
List empty();

List map(List L, int (*f) (int));
void mapInPlace(List L, int (*f) (int));

int mult (int x, int y) { return x * y; }

int main() {
    return 0;

    //int (*f)(int, int) = mult;

}


// A binary tree is either:
// - An empty tree
// - Or, a non-empty tree with a value and a left and right subtree

// A list is either:
// - An empty list
// - Or, a non-empty list with a head (value) and a tail (sublist, the next list)

// int addOne(int x) { return x + 1; }
// map([1, 2, 3], addOne)
// [2, 3, 4]
List map(List l, int (*f) (int)) {
    if (l == NULL) {
        return NULL;
    } else {
        return nonEmpty(f(l->head), map(l->tail, f));
    }
}


void mapInPlace(List l, int (*f) (int)) {
    if (l != NULL) {
        l->head = f(l->head);
        mapInPlace(l->tail, f);
    }
}

// +(a, b) = a + b
//
// foldr([1, 2, 3], +, 0)
// == 1 + (2 + (3 + 0))
//
// foldr(nonEmpty(1, nonEmpty(2, nonEmpty(3, NULL))), + , 0)
// == 1 + (2 + (3 + 0))

// foldr([1, 2, 3], *, 1)
// == 1 * (2 * (3 * 1))

// foldr(nonEmpty(1, [2, 3]), *, 1)
// == 1 * foldr([2, 3], *, 1)

// foldr([1, 2, 3], -, 0)
// == 1 - (2 - (3 - 0))
// != (1 - 2) - (3 - 0)

int foldr(List l, int (*f) (int, int), int z) {
	if (l == NULL) {
        return z;
    } else {
        return f(l->head, foldr(l->tail, f, z));
    }
}

// +(a, b) = a + b
//
// foldl([1, 2, 3], +, 0)
// == ((0 + 1) + 2) + 3
// != 1 + (2 + (3 + 0))

// foldl([1, 2, 3], *, 1)
// == ((1 * 2) * 2) * 3

// foldr([1, 2, 3], -, 0)
// == ((0 - 1) - 2) - 3
int foldl(List l, int (*f) (int, int), int z) {
    if (l == NULL) {
        return z;
    } else {
        return foldr(l->tail, f, f(l->head, z));
    }
}

// List

int isEmpty(List l) {
    return l == NULL;
}

// nonEmpty(3, [4, 5]) = [3, 4, 5]
// [4, 5] = nonEmpty(4, nonEmpty(5, NULL));



List nonEmpty(int head, List tail) {
    List l = malloc(sizeof(struct list));
    l->head = head;
    l->tail = tail;
    return l;
}

List empty() {
    return NULL;
}
