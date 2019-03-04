#include "file.h"

int count = 0;
int length = 0;

int main() {
	Record* arr;
	arr = populate(arr, MAX);
	clock_t start = clock();
	insertionSort(arr, count);
	clock_t end = clock();
	printRec(arr, count);
	printf("Time taken for insertion sort: %lf\n", (double)(end-start)/CLOCKS_PER_SEC);
}


Record* populate(Record * arr, int size) {
	FILE* fp;
	fp = fopen("10000", "r");
	if(fp==NULL) {
		printf("File could not be found\n");
		exit(1);
	}
	if(!length) {
		arr = (Record*) malloc(sizeof(Record)*size);
		length+=sizeof(Record)*size;
	}

	int i = 0;
	while(!(feof(fp))) {
		fscanf(fp, "\"%llu, %[^,], %[^,], %[^,], %[^\"]\"\n", &(arr[i].number), arr[i].code, arr[i].date, arr[i].first_name, arr[i].last_name);
		i++;
		count++;
		//insertInOrder(arr, i);	
	}
	return arr;
}


void printRec(Record* arr, int size) {
	int i = 0;
	while(i<size) {
		printf("%llu %s %s %s %s\n", arr[i].number, arr[i].code, arr[i].date, arr[i].first_name, arr[i].last_name);
		i++;
	}
}


void insertInOrder(Record* arr, int i) {
	Record temp = arr[i-1];
	int j = i-2;
	while(j>=0 && (arr[j].number>temp.number)) {
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = temp;
}


void insertionSort(Record* arr, int n) {
	if(n==1) {
		return;
	}

	insertionSort(arr, n-1);
	insertInOrder(arr, n);
}