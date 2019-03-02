#include "alloc.h"

typedef struct node {
	int el;
	struct node * next;
}Node;


typedef struct list {
	Node* first;
	int size;
}List;


List* createList(List* ls, int n);

void printList(List* ls);

List* createCycle(List* ls);