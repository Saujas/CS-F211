#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


typedef struct Employee {
	char name[10];
	int empID;
}Record;

typedef Record arr[100000];


void populate(arr);

void printArr(arr);

void insertionSort(arr);

void quickSortRec(arr, int, int);

void quickSortIte(arr, int, int, int);

int partition(arr, int, int);

void swap(arr, int, int);

double* timeTaken(arr, double*, int);

int estimate(arr, double*, int size);
