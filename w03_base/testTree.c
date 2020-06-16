// By Matthew Di Meglio
#include <stdio.h>
#include <assert.h>
#include "Tree.h"

void testCountNodes();
void testDepth();
void testNodeDepth();
void testNthSmallest();

int main() {
    testCountNodes();
    testNodeDepth();
    testDepth();
    testNthSmallest();
    printf("All tests passed!\n");
    return 0;
}

void testCountNodes() {
    Tree t = branch(5,
                    branch(3,
                           leaf(),
                           branch(4,
                                  NULL,
                                  NULL)),
                    NULL);

    assert(countNodes(t) == 3);
    assert(countNodes(NULL) == 0);

    freeTree(t);
}

void testDepth() {
    Tree t;
    
    t = branch(5,
               branch(3,
                      leaf(),
                      branch(4,
                             leaf(),
                             leaf()
                            )
                     ),
               leaf()
              );

    assert(depth(t) == 3);
    freeTree(t);

    t = branch(5,
               branch(3,
                      leaf(),
                      leaf()
                     ),
               leaf()
              );

    assert(depth(t) == 2);
    freeTree(t);

    assert(depth(leaf()) == 0);
}

void testNodeDepth() {
    Tree t =
        branch(
            5,
            branch(
                3,
                NULL,
                branch(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    MaybeInt depth;
    depth = nodeDepth(t, 3);
    assert(isJust(depth) && justValue(depth) == 2);

    depth = nodeDepth(t, 5);
    assert(isJust(depth) && justValue(depth) == 1);

    depth = nodeDepth(t, 29);
    assert(isNothing(depth));

    depth = nodeDepth(t, -2);
    assert(isNothing(depth));

    freeTree(t);
}

void testNthSmallest() {
    Tree t =
        branch(
            5,
            branch(
                3,
                leaf(),
                branch(
                    4,
                    leaf(),
                    leaf()
                )
            ),
            leaf()
        );
    MaybeInt m;
    m = nthSmallest(t, 1);
    assert(isJust(m) && justValue(m) == 3);

    m = nthSmallest(t, 2);
    assert(isJust(m) && justValue(m) == 4);

    m = nthSmallest(t, 3);
    assert(isJust(m) && justValue(m) == 5);

    m = nthSmallest(t, 5);
    assert(isNothing(m));

    freeTree(t);
}