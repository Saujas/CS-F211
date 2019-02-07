#include<stdio.h>
#include<stdlib.h>
//#include "alloc.c"
#include "list.h"
#include<time.h>

List * myalloc(int n)
{
	List * ptr = (List *) calloc(n, sizeof(List));
	return ptr;
}


List * createList(int n)
{
	List *Ls = myalloc(n);
	time_t t;
	List *temp = Ls;
	List *tmp = temp;
	int a;
	srand((unsigned) time(&t));
	a = rand()%1000;
	temp->el = a;
	for(int i = 1; i<n; i++)
	{
		a = rand()%1000;
		temp->next->el = a;
		temp = temp->next;
		tmp = tmp->next;
	}
	temp -> next = NULL;
	return Ls;
}

int main()
{
	List * p;
	p = createList(10);
	List *temp = p;
	while(temp)
	{
		printf("%d\t", temp->el);
		temp = temp->next;
	}
}
