#include "que.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	Queue * q = newQ();
	q = addQ(q, 7);
	print(q);
	print(addQ(q, 8));
	print(addQ(q, 3));
	print(addQ(q, 4));
	printf("%d\n", lengthQ(q));
	print(delQ(q));
	printf("%d\n", lengthQ(q));
	printf("%d\n", front(q));
	print(addQ(q, 5));
	print(addQ(q, 7));
	print(delQ(q));
	print(delQ(q));
	
}

Queue * newQ()
{
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	return q; 	
}


Queue * addQ(Queue * q, int e)
{
	Node *n = (Node *) malloc(sizeof(Node));
	n->element = e;
	n->next = NULL;
	if(q->head==NULL)
		q->head = n;
	else
		(q->tail)->next = n;
	q->tail = n;
	return q;
}

int front(Queue * q)
{
	printf("Front element: ");
	return ((q->head)->element);
}

Queue * delQ(Queue *q)
{
	q->head = (q->head)->next;
	return q;
}

int lengthQ(Queue *q)
{
	Node *temp;
	temp = q->head;
	int c = 0;
	while(temp)
	{
		c++;
		temp = temp->next;
	}
	printf("Length: ");
	return c;
}

void print(Queue *q)
{
	Node *temp;
	temp = q->head;
	while(temp)
	{
		printf("%d ", temp->element);
		temp = temp->next;
	}
	printf("\n");
}
                                                                 
