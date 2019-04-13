#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	char name[50];
	struct node* child;
	struct node* sibling;
}Node;


void readData(Node*, FILE*);

void lookup(Node*, FILE*);

void readName(Node*, char*, char*);

void findName(Node*, char*);

char ** split(char*);

Node* insert(Node*, char**, int);

Node* newNode(Node*);

Node* find(Node*, char*);

void traverse(Node*);

Node* locate(Node*, char**, int);

void locate1(Node*, char**, int);
