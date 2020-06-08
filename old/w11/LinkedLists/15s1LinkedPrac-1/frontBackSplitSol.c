// frontBackSplit.c
// 
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-ppexam.h"

// given a list of nodes, split it into two sublists 
// - one for the front half, and one for the back half. 
// If the number of elements is odd, the extra element 
// should go in the front list. 

// The first argument (sourceList) is the original list.
// The second argument (frontList) which is initally empty 
// should point to the front half of the list.
// The third argument (backList) which is initially empty
// should point to the back half of the list.
// The original list (sourceList) should be empty after the split.
//
// Constraints:
// don't malloc any new nodes
// don't change the "value" field of any node, just change links
// don't delete any nodes (i.e. do not call free())

// e.g. if sourceList is 1->4->6->4->3->X then 
// after execution of the function frontBackSplit() 
// frontList should be 1->4->6->X and 
// backList should be 4->3->X and
// sourceList should be X (i.e. empty)
//
// and if sourceList is 3->10->15->25->X then
// after execution of the function frontBackSplit() 
// frontList should be 3->10->X and
// backList should be 15->25->X
// sourceList should be X (i.e. empty)

// A function to determine the length of a list called numItems() 
// is provided. Fell free to use it but do not modify the function.

//function to determine length of a linked list
int numItems (list l) {

	int length = 0;
	link current = l->head;
	while (current != NULL){
		length++;
		current = current->next;
	}
	return length;
}

void insertFront(list l, link n) {
	n->next = l->head;
	l->head = n;
}

link removeFront(list l) {
	assert(l->head != NULL);
	link n = l->head;
	l->head = n->next;
	return n;
}

void frontBackSplit (list sourceList, list frontList, list backList) {
	backList->head = sourceList->head;
	sourceList->head = NULL;
	frontList->head = NULL;

	while(numItems(backList) > numItems(sourceList)) {
		insertFront(sourceList, removeFront(backList));
	}

	while(sourceList->head != NULL) {
		insertFront(frontList, removeFront(sourceList));
	}
}
/*
void frontBackSplit (list sourceList, list frontList, list backList) {
	
	if (sourceList->head != NULL) {
		link first = sourceList->head;
		link second = sourceList->head->next;

		while(second != NULL && second->next != NULL) {
			first = first->next;
			second = second->next->next;
		}

		backList->head = first->next;
		first->next = NULL;

		frontList->head = sourceList->head;
	} else {
		backList->head = NULL;
	}
	
	sourceList->head = NULL;
}



void frontBackSplit (list sourceList, list frontList, list backList) {
	frontList->head = NULL;

	int numForFront = (numItems(sourceList) + 1)/2;
	while(numForFront > 0) {
		insertFront(frontList, removeFront(sourceList));
		numForFront--;
	}

	backList->head = sourceList->head;
	sourceList->head = NULL;


	while(frontList->head != NULL) {
		insertFront(sourceList, removeFront(frontList));
	}

	frontList->head = sourceList->head;
	sourceList->head = NULL;
}


void frontBackSplit (list sourceList, list frontList, list backList) {
	int numForFront = (numItems(sourceList) + 1)/2;
	link curr = sourceList->head;

	while(numForFront - 1> 0) {
		curr = curr->next;
		numForFront--;
	}

	if (curr != NULL) {
		backList->head = curr->next;
		curr->next = NULL;
	} else {
		backList->head = NULL;
	}
	frontList->head = sourceList->head;
	sourceList->head = NULL;

}*/

