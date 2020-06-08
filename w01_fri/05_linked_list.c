#include <stdio.h>
#include <stdlib.h>

// struct complex {
//     double real;
//     double imaginary;
// }
// typedef struct complex complex;

// NULL
// struct nonEmptyList
//     first 
//     rest

// NULL
// nonEmptyList(3, NULL)
// nonEmptyList(4, nonEmptyList(2, NULL))

// typedef struct nonEmptyList *list;
// struct nonEmptyList {
//     int first;
//     list rest;
// }

struct node {
	int value;
	struct node *next;
};

typedef struct node node;
typedef node *list; 

typedef struct node * list

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
    int sum = 0;

    node *cur = l;
    while (cur != NULL) {
        sum += cur->value;
        cur = cur->next;
    }
    return sum;
}