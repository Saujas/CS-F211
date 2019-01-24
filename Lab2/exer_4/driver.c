#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
	FILE *ptr = fopen(argv[1], "r");
	
	struct linkedlist * head = (struct linkedlist *) malloc (sizeof(struct linkedlist));
	
	while(!feof(ptr))
	{
		int temp;
		fscanf(ptr, "%d ", &temp);
		insertFirst(head, temp);
	}
	fclose(ptr);
	
	printList(head);
	
	printf("\n%d\n", deleteFirst(head)->element);
	
	printList(head);
}	
