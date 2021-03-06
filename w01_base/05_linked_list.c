#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node node;
typedef node *list; 

int sumList(list l);

int main(int argc, char *argv[]) {
    node n1 = {1, NULL};
    node n2 = {4, &n1};
    node n3 = {2, &n2};
    // Alternately:
    // node n3;
    // n3.value = 2;
    // n3.next = &n2;

    list l = &n3;
    l->value = 2;
    l->next = &n2;
    // Alternately:
    // (*l).value = 2;
    // (*l).next = &n2;

    printf("Sum of 2->4->1->X is %d\n", sumList(l));
    return 0;
}


int sumList(list l) {
    // TODO - iteratively, then recursively
    return 0;
}