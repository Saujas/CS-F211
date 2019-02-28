#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Employee {
	char name[10];
	int empID;
}Record;

typedef Record arr[10000];


void populate(arr);

void printArr(arr);

void insertionSort(arr);

void quickSortRec(arr, int, int);

void quickSortIte(arr, int, int);

int partition(arr, int, int);

void swap(arr, int, int);
