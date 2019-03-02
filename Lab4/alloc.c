#include "alloc.h"

int main()
{
	int *a;
	int *b;
	a = myalloc(10);
	printf("Mem:%d\n", mem);
	myFree(a, 10);
	printf("Mem:%d\n", mem);
	b = myalloc(10);
	printf("Mem:%d\n", mem);
	myFree(b, 10);
	printf("Mem:%d\n", mem);
	

	// int n = 0;
	// time_t t;
	// srand((unsigned) time(&t));
	// int *p;
	// for(;;)
	// {
	// 	// n = rand();
	// 	n += 100000;
	// 	//printf("Number %d: %d\n", i, n);
	// 	p = myalloc(n);
	// 	printf("First location of array %d: %p\n", n, &p);
	// 	printf("Last location of array %d: %p\n", n, &(p[n-1]));
	// }
}

int * myalloc(int n)
{
	int * ptr = (int *) malloc(n*sizeof(int));
	mem+= n*sizeof(*ptr);
	printf("\n%p\n", ptr);
	return ptr;
}

void myFree(int *p, int n)
{
	mem-=n*sizeof(*p);
	free(p);
	
}
