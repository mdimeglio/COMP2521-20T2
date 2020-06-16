// By Matthew Di Meglio
#ifndef TREE_H
#define TREE_H
#include "MaybeInt.h"

typedef struct branch *Tree;

Tree nonEmptyTree(int key, Tree left, Tree right);
Tree emptyTree();
void freeTree(Tree t);
int countNodes(Tree t);
int depth(Tree t);
MaybeInt nodeDepth(Tree t, int key);
MaybeInt nthSmallest(Tree t, int n);

#endif 