#include<stdio.h>
#include<stdlib.h>
#include "multiq.h"

int main()
{
	Multi * m = createMQ(10);
}

Multi * createMQ(int num)
{
	Multi * m = (Multi *) malloc(sizeof(Queue)*num);
	return m;
}
