#include<stdio.h>
#include<stdlib.h>

int count = 0;

int hash(char *, int, int);

int collision(char**, int, int, int);

char ** parse();

int main() {
	/*char s[10][100];
	int base;
	int size;
	char ch;
	printf("Enter base: ");
	scanf("%d", &base);
	printf("Enter table size: ");
	scanf("%d", &size);
	getchar();
	int i=0;
	do {
		printf("Enter string: ");
		scanf("%[^\n]", s[i]);
		getchar();	
		printf("Press ! to exit or any other key to continue: ");
		i++;
	}while(ch=getchar()!='!');
	printf("Number of collisions: %d\n", collision(s, 10, base, size)); */
	
	char *s[100] = {"saujas", "cdarkar"};
	printf("Number of collisions: %d\n", collision(s, 2, 9, 10));
	
	char** c = parse();
	printf("%s %s %s\n", c[5], c[7], c[30000]);
	
		
}


int hash(char* s, int base, int size) {
	char c = s[0];
	int i = 0;
	int sum = 0;
	while(c!='\0') {
		c = s[i];
		sum+= (int) c;
		i++;
	}
	printf("Sum: %d\n", sum);
	int result = (sum%base)%size;
	return result;
}


int collision(char** arr, int arr_size, int base, int size) {
	int a[size];
	int res;
	int c=0;
	
	for(int i = 0; i<size; i++)
		a[i] = 0;
		
	for(int i = 0; i < arr_size; i++) {
		res = hash(arr[i], base, size);
		a[res] = a[res] +1;
	}
	for(int j = 0; j<size; j++) {
		if(a[j]>1)
			c++;
	}
	return c;
}


char** parse() {
	FILE *fp; 
	fp = fopen("aliceinwonderland.txt", "r");
	if(fp == NULL) {
		printf("File not found\n");
		exit(1);
	}
	
	char s1[200];

	while(!feof(fp)) {
		fscanf(fp, " %s ", s1);
		count++;
	}
	fclose(fp);
	printf("%d\n", count);
	
	char **s;
	s = (char**) malloc(sizeof(char*)*count);
	
	FILE *fp1; 
	fp1 = fopen("aliceinwonderland.txt", "r");
	if(fp1 == NULL) {
		printf("File not found\n");
		exit(1);
	}
	
	int i = 0;
	while(!feof(fp)) {
		s[i] = (char*) malloc(sizeof(char)*200);
		fscanf(fp, " %s ", s[i]);
		i++;
	}
	fclose(fp);
	return s;
	
}


	
	
	
	
	
	
	
	
	
	
