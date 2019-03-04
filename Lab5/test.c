#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *s;
	s = (char *) malloc(100*sizeof(char));
	long long int t;
	int i;
	FILE *fp;
	char *token;
	fp = fopen("10", "r");
	for(i = 0 ; i<10; i++)
	{

		fscanf(fp, "\"%s\n", s);
		token = strtok(s, ",");
		sscanf(token, "%lld", &t);
		printf("%lld\n\n", t);
		while(token)
		{
			printf("%s ", token);
			token = strtok(NULL, ",\"");
			//sscanf(token, "%lld", &t);
			//printf("%lld", t);
		}
		//printf("%s\n", s);
		printf("\n");
	}
}
