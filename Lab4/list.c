#include "list.h"


List* createList(List* ls, int n) {
	ls = (List*) malloc(sizeof(List));

	ls->first = NULL;

	Node* temp;

	time_t t;

	srand((unsigned) time(&t));

	for(int i = 0; i<n; i++) {
		Node * n = (Node*) malloc(sizeof(Node));
		int random = rand()%1000;
		n->el = random;
		n->next = NULL;

		if(!(ls->first)) {
			ls->first = n;
			temp = ls->first;
		}

		else {
			temp->next = n;
			temp = temp->next;
		}
	}
	ls->size = n;
	return ls;
}


List* createCycle(List* ls) {
	time_t t;
	srand((unsigned) time(&t));

	int toss = rand()%2;
	if(toss==1) {
		printf("Toss: linear\n");
		return ls;
	}

	else {
		printf("Toss: Cyclic\n");
		int r = rand()%(ls->size);
		printf("R: %d\n", r);
		Node* temp = ls->first;
		Node* n;
		int i = 0;
		while(temp->next) {
			if(i==r) {
				n = temp;
			}
			temp = temp->next;
		}
		temp->next = n;
	}
	return ls;
}


void printList(List* ls) {
	Node* temp = ls->first;
	while(temp) {
		printf("%d\n", temp->el);
		temp = temp->next;
	}
}


int main() {
	List* ls;
	ls = createList(ls, 10);
	printList(ls);
	ls = createCycle(ls);
	//printList(ls);
}