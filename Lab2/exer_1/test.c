/* File: test.c */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int c = sizeof(argv[0])/sizeof(argv[0][0]);
	int n;
	c--;
	for(int i = 0; i<c;i++)
	{
		if (i==0 || i==1)
			continue;
		printf("%c", argv[0][i]);
	}
	printf(" ");
	for(int i = 1; i<argc; i++)
	{
		if(atoi(argv[i]))
		{
			n = atoi(argv[i]);
			printf("%d (int) ", n);
			continue;
		}
		printf("%s ", argv[i]);
	}
	printf("\n");
}
