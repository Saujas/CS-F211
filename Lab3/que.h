#include<stdio.h>
#include<stdbool.h>

typedef struct node {
	int element;
	struct node * next;
} Node;

typedef struct queue {
	Node * head;
	Node * tail;
} Queue;

Queue * newQ();

bool isEmpty(Queue * q);

Queue * delQ(Queue * q);

int front(Queue *q);

Queue * addQ(Queue *q, int e);

int lengthQ(Queue *q);

void print(Queue *q);
