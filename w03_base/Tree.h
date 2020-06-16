#ifndef TREE_H
#define TREE_H
#include "MaybeInt.h"

typedef struct branch *Tree;

Tree branch(int key, Tree left, Tree right);
Tree leaf();
void freeTree(Tree t);
int countNodes(Tree t);
int depth(Tree t);
MaybeInt nodeDepth(Tree t, int key);
MaybeInt nthSmallest(Tree t, int n);

#endif 