#include <stdlib.h>

Tree TreeCopy(Tree t, int depth) {
    if (depth < 0 || t == NULL) {
        return NULL;
    }

    Tree s = malloc(sizeof(*s));
    s->value = t->value;
    s->left = TreeCopy(t->left, depth - 1);
    s->right = TreeCopy(t->right, depth - 1);
    return s;
}


int depth(Tree t, int value) {
    if (t == NULL) {
        return -1;
    } else if (value == t->value) {
        return 0;
    } else if (value < t->value) {
        return 1 + depth(t->left, value);
    } else {
        return 1 + depth(t->right, value);
    }
}

bool TreeIsPerfectlyBalanced(Tree t) {
    return
        (t == NULL) ||
        (TreeIsPerfectlyBalanced(t->left) &&
            TreeIsPerfectlyBalanced(t->right) &&
            abs(count(t->left) - count(t->right)) <= 1);
}

List listSetDifference(List l1, List l2) {
    List diff = newList();

    for (Node c1 = l1->head; c1 != NULL; c1 = c1->next) {
        if (!isInList(c1->value, l2)) {
            insertFront(diff, c1->value);
        }
    }

    return diff;
}


// assume k is valid for t
int BSTreeGetKth(Tree t, int k) {
    if (k < size(t->left)) {
        return BSTreeGetKth(t->left, k);
    } else if (k == size(t->left)) {
        return t->value;
    } else {
        return BSTreeGetKth(t->right, k - size(t->left) - 1);
    }
}

