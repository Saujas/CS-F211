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


int search(struct linkedlist * head, int ele)
{
	struct node * temp = head->first;
	while(temp) {
		if(temp->element == ele) {
			printf("Element found: %d\n", ele);
			return 1;
		}
		temp = temp->next;
	}
	printf("Element not found\n");
	return 0;
}


struct node * delete(struct linkedlist * head, int ele)
{
	struct node * temp = head->first;
	if(temp->element == ele) {
		temp->next = head->first;
	}
	while(temp->next) {
		if((temp->next)->element == ele) {
			struct node * t = temp->next;
			temp->next = (temp->next)->next;
			head->count--;
			return t;
		}
		temp = temp -> next;
	}
	return NULL;
}