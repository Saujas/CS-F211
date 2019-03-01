#include "storage.h"

int count = 0;

void populate(arr array) {
	FILE *fp;
	fp = fopen("300", "r");
	
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


void quickSortIte(arr array, int l, int h, int s) {
	int stack[h-l+1];
	int top = -1;
	
	stack[++top] = l;
	stack[++top] = h;
	
	while(top >= 0) {
		h = stack[top--];
		l = stack[top--];
		
		int p = partition(array, l, h);
		
		if(p-1 > l && p-l>s) {
			stack[++top] = l;
			stack[++top] = p-1;
		}
		
		if(p+1 < h && h-p>s) {
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


double * timeTaken(arr array, double* timeArr, int size) {
	clock_t start, end;

	arr array1;
	arr array2;
	for(int i = 0; i<size; i++) {
		array1[i] = array[i];
		array2[i] = array[i];
	}

	start = clock();
	quickSortIte(array2, 0, count-1, 0);
	end = clock();
	timeArr[1] = ((double) (end-start)) / CLOCKS_PER_SEC;

	start = clock();
	insertionSort(array1);
	end = clock();
	timeArr[0] = ((double) (end-start)) / CLOCKS_PER_SEC;

	return timeArr;
}

int estimate(arr array, double* d, int size) {
	int min = 10;
	int max = size;
	int mid;
	do {
		mid = (min+max)/2;
		d = timeTaken(array, d, mid);
		printf("%lf %lf %d\n", d[0], d[1], mid);
		if(d[0]<d[1]) {
			min = mid;
			printf("Min: %d\n", min);
		}
		else {
			max = mid;
			printf("Max: %d\n", max);
		}
	}while(abs(d[0]*1000000-d[1]*1000000)>10);
	return mid;
}



int main() {
	arr array;
	populate(array);
	//printArr(array);
	//insertionSort(array);
	//printf("\nInsertion sorted:\n\n");
	//printf("\nQuick sorted: \n\n");
	//quickSortIte(array, 0, count-1, 0);
	//printArr(array);
	double *timeArr = (double*) malloc(sizeof(double)*2);
	//timeArr = timeTaken(array, timeArr, count);
	//printArr(array);
	int es = estimate(array, timeArr, 300);
	printf("Insertion sort time: %lf\nQuick sort time: %lf\n", timeArr[0], timeArr[1]);	
	printf("\nCutoff: %d\n", es);
}
	
