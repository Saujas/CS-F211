#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	FILE *f;
	FILE *g;
	if(argc != 3)
	{
		printf("Error. Format should be './copy src_file dest_file'\n");
		exit(1);
	}
	
	f = fopen(argv[1], "r");
	
	if(f == NULL)
	{
		printf("Error - No file %s exists\n", argv[1]);
		exit(1);
	}
	
	g = fopen(argv[2], "w");
	
	if(g == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	int ch = getc(f);
	while(ch != EOF)
	{
		fprintf(g, "%c", ch);
		ch = getc(f);
	}
	
	fclose(f);
	fclose(g);
} 
