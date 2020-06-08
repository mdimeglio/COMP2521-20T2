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

int length(List l);
List copy(List l);
bool isEqual(List l1, List l2);

int main() {
    List l1, l2;

    // LENGTH TESTS
    l1 = Empty();
    assert(length(l1) == 0);
    freeList(l1);

    // TODO: write more tests for length
    
    // COPY TESTS
    l1 = NonEmpty(2, NonEmpty(1, Empty()));
    l2 = copy(l1);
    assert(isEqual(l1, l1));
    assert(isEqual(l1, l2));
    freeList(l1);
    freeList(l2);

    // TODO: write more tests for copy

    printf("All tests passed!\n");
    return 0;
}

List Empty() {

}

List NonEmpty(int first, List rest) {

}

void freeList(List l) {

}

bool isEmpty(List l) {
    return true;
}

int length(List l) {
    return 0;
}

List copy(List l) {
    return l;
}

bool isEqual(List l1, List l2) {
    return true;
}

