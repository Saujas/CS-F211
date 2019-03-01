#include "que.h"


// int main()
// {
// 	Queue * q = newQ();
// 	print(q);
// 	q = addQ(q, 7);
// 	print(q);
// 	print(addQ(q, 8));
// 	print(addQ(q, 3));
// 	print(addQ(q, 4));
// 	printf("%d\n", lengthQ(q));
// 	print(delQ(q));
// 	printf("%d\n", lengthQ(q));
// 	printf("%d\n", front(q));
// 	print(addQ(q, 5));
// 	print(addQ(q, 7));
// 	print(delQ(q));
// 	print(delQ(q));
	
// }

Queue * newQ()
{
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	return q; 	
}


bool isEmpty(Queue * q)
{
	if(q->head == NULL) {
		return true;
	}
	else {
		return false;
	}
}


Node* newEl(int e, int p) {
	Node * n = (Node*) malloc(sizeof(Node));
	n->element = e;
	n->p = p;
	n->next = NULL;
	return n;
}


Queue * addQ(Queue * q, Node* n)
{
	if(isEmpty(q)) {
		q->head = n;
	}
	else {
		(q->tail)->next = n;
	}
	q->tail = n;
	return q;
}


int front(Queue * q)
{
	printf("Front element: ");
	if(isEmpty(q)) {
		printf("\nQueue empty\n");
		return 0;
	}
	return ((q->head)->element);
}


Queue * delQ(Queue *q)
{
	if(isEmpty(q)) {
		printf("\nQueue empty\n");
		return q;
	}
	else {
		q->head = (q->head)->next;
		return q;
	}
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
	if(isEmpty(q)) {
		printf("\nQueue empty\n");
		return;
	}
	temp = q->head;
	while(temp)
	{
		printf("%d ", temp->element);
		temp = temp->next;
	}
	printf("\n");
}
                                                                 
