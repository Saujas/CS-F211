#include "storage.h"

int count = 0;

void populate(arr array) {
	FILE *fp;
	fp = fopen("10000", "r");
	
	if(fp == NULL)
	{
		printf("Error. File not found\n");
		exit(1);
	}

	while(!feof(fp))
	{
		fscanf(fp, "%[^ ]", array[count].name);
		fscanf(fp, "%d\n", &(array[count].empID));
		count++;

	}
	fclose(fp);
}


void printArr(arr array) {
	for(int i = 0; i<count; i++)
	{
		printf("Name: %s\n", array[i].name);
		printf("ID: %d\n", array[i].empID);
	}
}


void quickSortRec(arr array, int low, int high) {
	int pi;
	if(low<high) {
		pi = partition(array, low, high);
		quickSortRec(array, low, pi-1);
		quickSortRec(array, pi+1, high);
	}	
}


int partition(arr array, int low, int high) {
	int pivot = array[high].empID;
	int i = low - 1;
	for(int j = low; j <= high - 1; j++) {
		if(array[j].empID <= pivot) {
			i++;
			swap(array, i, j);
		}
	}
	swap(array, i+1, high);
	return i+1;
}


void quickSortIte(arr array, int l, int h) {
	int stack[h-l+1];
	int top = -1;
	
	stack[++top] = l;
	stack[++top] = h;
	
	while(top >= 0) {
		h = stack[top--];
		l = stack[top--];
		
		int p = partition(array, l, h);
		
		if(p-1 > l) {
			stack[++top] = l;
			stack[++top] = p-1;
		}
		
		if(p+1 < h) {
			stack[++top] = p+1;
			stack[++top] = h;
		}
	}
}


void swap(arr array, int i, int j) {
	int temp;
	char c[10];
	
	temp = array[i].empID;
	strcpy(c, array[i].name);
	
	array[i].empID = array[j].empID;
	strcpy(array[i].name, array[j].name);
	
	array[j].empID = temp;
	strcpy(array[j].name, c);
}


void insertionSort(arr array) {
	int temp, i;
	char c[10];
	for(int j = 1; j<count; j++) {
		temp = array[j].empID;
		strcpy(c, array[j].name);
		i = j-1;
		while(i>=0 && array[i].empID > temp) {
			array[i+1].empID = array[i].empID;
			strcpy(array[i+1].name, array[i].name);
			i--;
		}
		array[i+1].empID = temp;
		strcpy(array[i+1].name, c);
	}
	return;
}


int main() {
	arr array;
	populate(array);
	printArr(array);
	//insertionSort(array);
	//printf("\nInsertion sorted:\n\n");
	printf("\nQuick sorted: \n\n");
	quickSortIte(array, 0, count-1);
	printArr(array);	
}
	
