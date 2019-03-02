#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int * myalloc(int n);
void myFree(int *, int);

int mem=0;
int size = 0;