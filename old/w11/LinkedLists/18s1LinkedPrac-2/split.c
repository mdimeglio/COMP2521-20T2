// split.c
// By Matthew Di Meglio 31/05/2018
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-ppexam.h"

// Started at 8am - 9:08 12:15 - 1:32

/*
 * PART A:
 * (5 marks)
 * 
 * length(l) should return the length of the list l.
 *
 * YOU ARE NOT ALLOWED TO CALL malloc OR free IN length!
 *
 * EXAMPLES:
 * l -> X, then length(l) == 0
 * l -> [1] -> X, then length(l) == 1
 * l -> [1] -> [1] -> X, then length(l) == 2
 */
int length (list l) {
	int len = 0;
	for(link cur = l->head; cur != NULL; cur = cur->next) {
		len++;
	}

	return len;
}

/*
 * PART B:
 * (5 marks)
 *
 * splitAtNode(l, n) should, if n is a node in the list l,
 * split the list just before the node n.
 *
 * YOU ARE NOT ALLOWED TO CALL malloc OR free IN splitAtNode!
 *
 * EXAMPLE 1. If
 * l -> [1] -> [1] -> [1] -> X
 *              ^
 * n -----------+
 * Then after calling splitAtNode(l, n), should have
 * l -> [1] -> X    [1] -> [1] -> X
 *                   ^
 * n ----------------+
 *
 * EXAMPLE 2. If
 * l -> [1] -> [2] -> [3] -> X
 *       ^
 * n ----+
 * Then after calling splitAtNode(l, n), should have
 * l -> X    [1] -> [2] -> [3] -> X
 *            ^
 * n ---------+
 *
 * EXAMPLE 3. If
 * l -> [1] -> [1] -> [1] -> X
 *       
 * n -> [1] -> [1] -> X
 * Then after calling splitAtNode(l, n), should have
 * l -> [1] -> [1] -> [1] -> X
 *       
 * n -> [1] -> [1] -> X
 */
void splitAtNode(list l, link n) {
	if (l->head == NULL) return;

	for(link cur = l->head;
			cur->next != NULL;
			cur = cur->next) {
		if (cur->next == n) {
			cur->next = NULL;
			return;
		}
	}
}

/*
 * triSplit(a, b, intersection) should, if the lists a and b
 * eventually merge, move the intersection of a and b to the list
 * called intersection, splitting it off from a and b.
 *
 * It is guaranteed that an empty list will always be passed in as the
 * intersection argument.
 *
 * YOU ARE NOT ALLOWED TO CALL malloc OR free IN triSplit!
 *
 * PART C (5 marks): trisplit is correct whenever length(a) == length(b)
 *
 * EXAMPLE 1:
 * INPUT:
 * a -> [1] -> [2] -+
 *                  |
 *                  v
 *                 [3] -> [4] -> X
 *                  ^
 *                  |
 * b -> [5] -> [6] -+
 * intersection -> X
 *
 * OUTPUT:
 * a -> [1] -> [2] -> X
 * b -> [5] -> [6] -> X
 * intersection -> [3] -> [4] -> X
 *
 * EXAMPLE 2:
 * INPUT:
 * a -> [1] -> [2] -> X
 * b -> [1] -> [2] -> X
 * intersection -> X
 *
 * OUTPUT:
 * a -> [1] -> [2] -> X
 * b -> [1] -> [2] -> X
 * intersection -> X
 *
 * EXAMPLE 3:
 * INPUT:
 * a -> [1] -> [2] -> X
 *       ^
 *       |
 * b ----+
 * intersection -> X
 *
 * OUTPUT:
 * a -> X
 * b -> X
 * intersection -> [1] -> [2] -> X
 *
 *
 * PART D (5 marks): triSplit is correct even if length(a) != length(b)
 *
 * EXAMPLE 1:
 * INPUT:
 * a -> [1] -> [2] -+
 *                  |
 *                  v
 *                 [3] -> [4] -> X
 *                  ^
 *                  |
 * b --------> [6] -+
 * intersection -> X
 *
 * OUTPUT:
 * a -> [1] -> [2] -> X
 * b -> [6] -> X
 * intersection -> [3] -> [4] -> X
 *
 */
void triSplit(list a, list b, list intersection) {
	// TO DO
}