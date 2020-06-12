#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct NonEmptyList *List;
struct NonEmptyList {
   int first;
   List rest;
};

List Empty();
List NonEmpty(int first, List rest);
void freeList(List l);
bool isEmpty(List l);

int length(List l) {
    // TODO
    return 0;
}
int main() {
    List l1, l2;

    // LENGTH TESTS
    l1 = Empty();
    assert(length(l1) == 0);
    freeList(l1);

    // TODO: write more tests for length

    printf("All tests passed!\n");
    return 0;
}

// Helper functions

bool isEmpty(List l) {
    return true;
}

List Empty() {
    return NULL;
}

List NonEmpty(int first, List rest) {
    List l = malloc(sizeof (struct list));
    l->first = first;
    l->rest = rest;
    return l;
}

void freeList(List l) {
    if (!isEmpty(l)) {
        freeList(l->rest);
        free(l);
    }
}
