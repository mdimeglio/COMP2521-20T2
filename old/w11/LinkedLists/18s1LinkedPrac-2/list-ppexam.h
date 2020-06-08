typedef struct _node *link;    // a link points to a node
 
typedef struct _node {
    int value;
	link next;
} node;
 
// a list is represented by a pointer to a struct which contains 
// a pointer to the first node of the list called the "head"
typedef struct _list {
    link head;
} *list; 

void showList (list l); // implementation of this function is provided in testSplit.c
int length (list l); // for you to implement in split.c
void splitAtNode(list l, link n); // for you to implement in split.c
void triSplit(list a, list b, list intersection); // for you to implement in split.c
