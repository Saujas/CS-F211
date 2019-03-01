#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
	int element;
	struct node * next;
	int p;
} Node;

typedef struct queue {
	Node * head;
	Node * tail;
	int p;
} Queue;

Queue * newQ();

Node* newEl(int e, int p);

bool isEmpty(Queue * q);

Queue * delQ(Queue * q);

int front(Queue *q);

Queue * addQ(Queue *q, Node*);

int lengthQ(Queue *q);

void print(Queue *q);
