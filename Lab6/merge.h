#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct list {
	char name[11];
	float cgpa;
} Element; 


void merge(Element*, int, Element*, int, Element*);

void mergeSortRec(Element*, int);

void mergeSortIte(Element*, int);

void printArr(Element*, int);
