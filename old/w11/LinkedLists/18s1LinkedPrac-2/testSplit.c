// testSplit.c
// By Matthew Di Meglio 31/05/2018

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list-ppexam.h"

static int testLength();
static int testSplitAtNode();
static int testEqualLengthTriSplit();
static int testUnequalLengthTriSplit();

void showList (list l); // Implemented in this file further down

int main (int argc, char * argv[]){
    int numSectionsPassed
        = testLength()
        + testSplitAtNode()
        + testEqualLengthTriSplit()
        + testUnequalLengthTriSplit();
    
    printf("Marks awarded: %d/20.\n", numSectionsPassed*5);
    if (numSectionsPassed == 4) {
        printf("All tests passed! You are awesome!\n");
    }
	
	return EXIT_SUCCESS;
}

list newList(int length, link nodes[]) {
    list l = malloc(sizeof (struct _list));
    l->head = NULL;

    int i = length - 1;
    while (i >= 0) {
        nodes[i] = malloc(sizeof(node));
        nodes[i]->next = l->head;
        l->head = nodes[i];
        i--;
    }

    return l;
}

int areNodesCorrectlyLinked(int length, link nodes[]) {
    if (length == 0) return 1;

    int i = 1;
    while(i < length) {
        if (nodes[i-1]->next != nodes[i]) {
            return 0;
        }
        i++;
    }

    if (nodes[i-1]->next != NULL) {
        return 0;
    }

    return 1;
}


int isListCorrectlyLinked(list l, int length, link nodes[]) {
    if (length == 0) {
        return l->head == NULL;
    }

    if (l->head != nodes[0]) {
        return 0;
    }

    return areNodesCorrectlyLinked(length, nodes);
    
}

void freeNodes(int length, link nodes[]) {
    int i = 0;
    while (i < length) {
        free(nodes[i]);
        nodes[i] = NULL;
        i++;
    }
}

void freeList(list l, int length, link nodes[]) {
    free (l);
    freeNodes(length, nodes); 
}




int testLength() {
    int passed = 1;
    list l;
    link nodes[4];
    int len;
    int listLinked;

    printf("TESTING PART A: length()...\n");

    printf("# Length 0 list...");
    l = newList(0, nodes);
    len = length(l);
    listLinked = isListCorrectlyLinked(l, 0, NULL);
    freeList(l, 0, nodes);
    if (len != 0) {
        printf("failed! Your length was %d.\n", len);
        passed = 0;
    } else if (!listLinked) {
        printf("failed! After calling length, list no longer linked correctly.\n");
        passed = 0;
    } else {
        printf("passed!\n");
    }

    printf("# Length 1 list...");
    l = newList(1, nodes);
    len = length(l);
    listLinked = isListCorrectlyLinked(l, 1, nodes);
    freeList(l, 1, nodes);
    if (len != 1) {
        printf("failed! Your length was %d.\n", len);
        passed = 0;
    } else if (!listLinked) {
        printf("failed! After calling length, list no longer linked correctly.\n");
        passed = 0;
    } else {
        printf("passed!\n");
    }

    printf("# Length 4 list...");
    l = newList(4, nodes);
    len = length(l);
    listLinked = isListCorrectlyLinked(l, 4, nodes);
    freeList(l, 4, nodes);
    if (len != 4) {
        printf("failed! Your length was %d.\n", len);
        passed = 0;
    } else if (!listLinked) {
        printf("failed! After calling length, list no longer linked correctly.\n");
        passed = 0;
    } else {
        printf("passed!\n");
    }

    if (passed) {
        printf("...PASSED PART A!\n\n");
    } else {
        printf("...FAILED PART A!\n\n");
    }

    return passed;
}

int testSplitAtNode() {
    int passed = 1;
    list l, m;
    link nodes[4];
    int listLinked;

    printf("TESTING PART B: splitAtNode(l, n)...\n");

    printf("# length(l) == 0, n == NULL ...");
    l = newList(0, NULL);
    splitAtNode(l, NULL);
    listLinked = isListCorrectlyLinked(l, 0, NULL);
    freeList(l, 0, NULL);
    if (listLinked) {
        printf("passed!\n");
    } else {
        printf("failed! A list wasn't linked correctly.\n");
        passed = 0;
    }
    

    printf("# length(l) == 0, n from another list ...");
    l = newList(0, NULL);
    m = newList(3, nodes);
    
    splitAtNode(l, m->head);
    listLinked = isListCorrectlyLinked(l, 0, NULL) && isListCorrectlyLinked(m, 3, nodes);
    freeList(l, 0, NULL);
    freeList(m, 0, nodes);

    if (listLinked) {
        printf("passed!\n");
    } else {
        printf("failed! A list wasn't linked correctly.\n");
        passed = 0;
    }
    

    printf("# length(l) == 1, n == l->head ...");
    l = newList(1, nodes);
    splitAtNode(l, l->head);
    listLinked = isListCorrectlyLinked(l, 0, NULL) && areNodesCorrectlyLinked(1, nodes);
    freeList(l, 1, nodes);
    if (listLinked) {
        printf("passed!\n");
    } else {
        printf("failed! A list wasn't linked correctly.\n");
        passed = 0;
    }

    printf("# length(l) == 3, n == l->head...");
    l = newList(3, nodes);
    splitAtNode(l, l->head);
    listLinked = isListCorrectlyLinked(l, 0, NULL) && areNodesCorrectlyLinked(3, nodes);
    freeList(l, 3, nodes);
    if (listLinked) {
        printf("passed!\n");
    } else {
        printf("failed! A list wasn't linked correctly.\n");
        passed = 0;
    }

    printf("# length(l) == 4, n == l->head->next...");
    l = newList(4, nodes);
    splitAtNode(l, l->head->next);
    listLinked = isListCorrectlyLinked(l, 1, nodes) && areNodesCorrectlyLinked(3, &nodes[1]);
    freeList(l, 4, nodes);
    if (listLinked) {
        printf("passed!\n");
    } else {
        printf("failed! A list wasn't linked correctly.\n");
        passed = 0;
    }

    printf("# length(l) == 4, n == NULL...");
    l = newList(4, nodes);
    splitAtNode(l, NULL);
    listLinked = isListCorrectlyLinked(l, 4, nodes);
    freeList(l, 4, nodes);
    if (listLinked) {
        printf("passed!\n");
    } else {
        printf("failed! A list wasn't linked correctly.\n");
        passed = 0;
    }

    printf("# length(l) == 4, n from another list...");
    l = newList(2, nodes);
    m = newList(2, &nodes[2]);
    splitAtNode(l, m->head);
    listLinked = isListCorrectlyLinked(l, 2, nodes) && isListCorrectlyLinked(m, 2, &nodes[2]);
    freeList(l, 2, nodes);
    freeList(m, 2, &nodes[2]);
    if (listLinked) {
        printf("passed!\n");
    } else {
        printf("failed! A list wasn't linked correctly.\n");
        passed = 0;
    }

    if (passed) {
        printf("PASSED PART B!\n\n");
    } else {
        printf("FAILED PART B!\n\n");
    }

    return passed;
}

int testEqualLengthTriSplit() {
    // Manually print the lists! (so as not to show how to deal with them in print solution)
    printf("TESTING PART C: equal length triSplit(a, b, intersection)...\n");

    list a, b, intersection;
    link aNodes[5];
    link bNodes[5];
    link intersectionNodes[5];
    int passed = 1;

    printf("# length(a) == 0, length(b) == 0, no intersection...\n");
    a = newList(0, NULL);
    b = newList(0, NULL);
    intersection = newList(0, NULL);

    triSplit(a, b, intersection);

    if (!isListCorrectlyLinked(a, 0, NULL)) {
        printf("# ...failed! List a wasn't empty.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(b, 0, NULL)) {
        printf("# ...failed! List b wasn't empty.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(intersection, 0, NULL)) {
        printf("# ...failed! List intersection wasn't empty.\n");
        passed = 0;
    } else {
        printf("# ...passed!\n");
    }

    freeList(a, 0, NULL);
    freeList(b, 0, NULL);
    freeList(intersection, 0, NULL);


    printf("# length(a) == 2, length(b) == 2, no intersection...\n");
    a = newList(2, aNodes);
    b = newList(2, bNodes);
    intersection = newList(0, NULL);

    triSplit(a, b, intersection);

    if (!isListCorrectlyLinked(a, 2, aNodes)) {
        printf("# ...failed! List a wasn't unchanged.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(b, 2, bNodes)) {
        printf("# ...failed! List b wasn't unchanged.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(intersection, 0, NULL)) {
        printf("# ...failed! List intersection wasn't empty.\n");
        passed = 0;
    } else {
        printf("# ...passed!\n");
    }

    freeList(a, 2, aNodes);
    freeList(b, 2, bNodes);
    freeList(intersection, 0, NULL);


    printf("# length(a) == 2, length(b) == 2, intersection from start...\n");
    a = newList(0, aNodes);
    b = newList(0, bNodes);
    intersection = newList(2, intersectionNodes);
    a->head = intersection->head;
    b->head = intersection->head;
    intersection->head = NULL;

    triSplit(a, b, intersection);

    if (!isListCorrectlyLinked(a, 0, aNodes)) {
        printf("# ...failed! List a wasn't empty.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(b, 0, bNodes)) {
        printf("# ...failed! List b wasn't empty.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(intersection, 2, intersectionNodes)) {
        printf("# ...failed! List intersection wasn't correct.\n");
        passed = 0;
    } else {
        printf("# ...passed!\n");
    }

    freeList(a, 0, aNodes);
    freeList(b, 0, bNodes);
    freeList(intersection, 2, intersectionNodes);


    printf("# length(a) == 4, length(b) == 4, intersection from 2nd node to end inclusive...\n");
    a = newList(1, aNodes);
    b = newList(1, bNodes);
    intersection = newList(3, intersectionNodes);
    a->head->next = intersection->head;
    b->head->next = intersection->head;
    intersection->head = NULL;

    triSplit(a, b, intersection);

    if (!isListCorrectlyLinked(a, 1, aNodes)) {
        printf("# ...failed! List a wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(b, 1, bNodes)) {
        printf("# ...failed! List b wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(intersection, 3, intersectionNodes)) {
        printf("# ...failed! List intersection wasn't correct.\n");
        passed = 0;
    } else {
        printf("# ...passed!\n");
    }

    freeList(a, 1, aNodes);
    freeList(b, 1, bNodes);
    freeList(intersection, 3, intersectionNodes);


    if (passed) {
        printf("PASSED PART C!\n\n");
    } else {
        printf("FAILED PART C!\n\n");
    }

    return passed;
}

int testUnequalLengthTriSplit() {
    // Manually print the lists! (so as not to show how to deal with them in print solution)
    printf("TESTING PART C: equal length triSplit(a, b, intersection)...\n");

    list a, b, intersection;
    link aNodes[5];
    link bNodes[5];
    link intersectionNodes[5];
    int passed = 1;

    printf("# Input Lists:\n");
    printf("# a -> [1] -> [1] -> [1] -> X\n");
    printf("# b -> X\n");
    printf("# no intersection...\n");

    a = newList(3, aNodes);
    b = newList(0, bNodes);
    intersection = newList(0, intersectionNodes);
    //a->head->next = intersection->head;
    //b->head->next = intersection->head;
    //intersection->head = NULL;

    triSplit(a, b, intersection);

    if (!isListCorrectlyLinked(a, 3, aNodes)) {
        printf("# ...failed! List a wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(b, 0, bNodes)) {
        printf("# ...failed! List b wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(intersection, 0, intersectionNodes)) {
        printf("# ...failed! List intersection wasn't correct.\n");
        passed = 0;
    } else {
        printf("# ...passed!\n");
    }

    printf("#\n");

    freeList(a, 3, aNodes);
    freeList(b, 0, bNodes);
    freeList(intersection, 0, intersectionNodes);

    printf("# Input Lists:\n");
    printf("# a -> [1] -> [1] -> [1] -> X\n");
    printf("#              ^\n");
    printf("#              |\n");
    printf("# b -----------+\n");
    printf("# intersection size 2...\n");

    a = newList(1, aNodes);
    b = newList(0, bNodes);
    intersection = newList(2, intersectionNodes);
    a->head->next = intersection->head;
    b->head = intersection->head;
    intersection->head = NULL;

    triSplit(a, b, intersection);

    if (!isListCorrectlyLinked(a, 1, aNodes)) {
        printf("# ...failed! List a wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(b, 0, bNodes)) {
        printf("# ...failed! List b wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(intersection, 2, intersectionNodes)) {
        printf("# ...failed! List intersection wasn't correct.\n");
        passed = 0;
    } else {
        printf("# ...passed!\n");
    }

    freeList(a, 1, aNodes);
    freeList(b, 0, bNodes);
    freeList(intersection, 2, intersectionNodes);

    printf("#\n");

    printf("# Input Lists:\n");
    printf("# b -> [1] -> [1] -> [1] -> X\n");
    printf("#              ^\n");
    printf("#              |\n");
    printf("# a -----------+\n");
    printf("# intersection size 2...\n");

    b = newList(1, bNodes);
    a = newList(0, aNodes);
    intersection = newList(2, intersectionNodes);
    b->head->next = intersection->head;
    a->head = intersection->head;
    intersection->head = NULL;

    triSplit(a, b, intersection);

    if (!isListCorrectlyLinked(b, 1, bNodes)) {
        printf("# ...failed! List b wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(a, 0, aNodes)) {
        printf("# ...failed! List a wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(intersection, 2, intersectionNodes)) {
        printf("# ...failed! List intersection wasn't correct.\n");
        passed = 0;
    } else {
        printf("# ...passed!\n");
    }

    freeList(b, 1, aNodes);
    freeList(a, 0, bNodes);
    freeList(intersection, 2, intersectionNodes);

    printf("#\n");

    printf("# Input Lists:\n");
    printf("# a -> [1] -> [1] -> [1] -> X\n");
    printf("#                     ^\n");
    printf("#                     |\n");
    printf("# b ---[1]------------+\n");
    printf("# intersection size 1...\n");

    a = newList(2, aNodes);
    b = newList(1, bNodes);
    intersection = newList(1, intersectionNodes);
    a->head->next->next = intersection->head;
    b->head->next = intersection->head;
    intersection->head = NULL;

    triSplit(a, b, intersection);

    if (!isListCorrectlyLinked(a, 2, aNodes)) {
        printf("# ...failed! List a wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(b, 1, bNodes)) {
        printf("# ...failed! List b wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(intersection, 1, intersectionNodes)) {
        printf("# ...failed! List intersection wasn't correct.\n");
        passed = 0;
    } else {
        printf("# ...passed!\n");
    }

    freeList(a, 2, aNodes);
    freeList(b, 1, bNodes);
    freeList(intersection, 1, intersectionNodes);

    printf("#\n");

    printf("# Input Lists:\n");
    printf("# b -> [1] -> [1] -> [1] -> X\n");
    printf("#                     ^\n");
    printf("#                     |\n");
    printf("# a ---[1]------------+\n");
    printf("# intersection size 1...\n");

    b = newList(2, bNodes);
    a = newList(1, aNodes);
    intersection = newList(1, intersectionNodes);
    b->head->next->next = intersection->head;
    a->head->next = intersection->head;
    intersection->head = NULL;

    triSplit(a, b, intersection);

    if (!isListCorrectlyLinked(b, 2, bNodes)) {
        printf("# ...failed! List b wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(a, 1, aNodes)) {
        printf("# ...failed! List a wasn't correct.\n");
        passed = 0;
    } else if (!isListCorrectlyLinked(intersection, 1, intersectionNodes)) {
        printf("# ...failed! List intersection wasn't correct.\n");
        passed = 0;
    } else {
        printf("# ...passed!\n");
    }

    freeList(b, 2, aNodes);
    freeList(a, 1, bNodes);
    freeList(intersection, 1, intersectionNodes);

    printf("#\n");

    if (passed) {
        printf("PASSED PART D!\n\n");
    } else {
        printf("FAILED PART D!\n\n");
    }

    return passed;
}

void showList (list l) {
    assert (l !=NULL);

    // start at the first node
    link current = l->head;
    while (current != NULL) {
        printf ("%p : { value: %d, next: %p }\n", current, current->value, current->next);
        current = current->next;
    }
}
