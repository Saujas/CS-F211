#include "linkedlist.h"
#include<stdlib.h>

void insertFirst(struct linkedlist* head, int ele)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link -> element = ele;
	link->next = head->first;
	head->first = link;
	head->count ++;
}

struct node * deleteFirst(struct linkedlist * head)
{
	struct node * temp = head -> first;
	head->first = temp->next;
	head -> count --;
	return temp;
}

void printList(struct linkedlist * head)
{
	struct node *ptr = head->first;
	printf("\n[ ");

	while(ptr != NULL)
	{        
		printf("%d,",ptr->element);
		ptr = ptr->next;
	}
	printf(" ]\n");
}
