#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100000

typedef struct record {
	unsigned long long int number;
	char code[20];
	char date[20];
	char first_name[20];
	char last_name[20];
} Record;


Record* populate(Record*, int);

void printRec(Record*, int);

void insertInOrder(Record*, int);

void insertionSort(Record*, int);