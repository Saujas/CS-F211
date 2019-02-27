/* File: test.c */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int n;
	int c = 2;
	char name[sizeof(argv[0])];
	
	while(c < sizeof(argv[0]))
	{
		name[c-2] = argv[0][c];
		c++;
	}

	printf("%s ", name);

	for(int i = 1; i<argc; i++)
	{
		if(atoi(argv[i]))
		{
			n = atoi(argv[i]);
			printf("%d(int) ", n);
			continue;
		}
		printf("%s ", argv[i]);
	}
	printf("\n");
}
