#include<stdio.h>
#include<stdlib.h>
#include "multiq.h"

int main()
{
	Multi* m = createMQ(10);
}

Multi* createMQ(int num)
{
	Multi *m = (Multi*) malloc(sizeof(Queue)*num);
	for(int i = 0; i<num; i++) {
		m[i] = newQ();
		m[i]->p = i;
	}
	return m;
}

Multi* addMQ(Multi* m, Task t) {
	int p = t -> p;
	int s = sizeMQ(m);
	if(p<0 || p>=s) {
		printf("Priority given does not exist\n");
		return m;	
	}
	addQ(m[p], t);
	return m;
}

int sizeMQ(Multi *m) {
	int s = sizeof(m)/sizeof(Queue);
	return s;
}
