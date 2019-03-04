#include "merge.h"


void merge(Element ls1[], int s1, Element ls2[], int s2, Element ls[])
{

	int i = 0, j = 0;
	int k = 0;
	int l = s1;
	int s = s2;
	if(s2>s1)
	{
		l = s2;
		s = s1;
	}
	for(i = 0; i<l && j<s;)
	{
		
		if(l == s1)
		{
			if(ls1[i].cgpa<ls2[j].cgpa)
			{
				ls[k].cgpa = ls1[i].cgpa;
				strcpy(ls[k].name, ls1[i].name);
				i++; k++;
			}
			else
			{
				ls[k].cgpa = ls2[j].cgpa;
				strcpy(ls[k].name, ls2[j].name);
				j++; k++;
			}
		}
		else
		{
			if(ls2[i].cgpa<ls1[j].cgpa)
			{
				ls[k].cgpa = ls2[i].cgpa;
				strcpy(ls[k].name, ls2[i].name);
				i++; k++;
			}
			else
			{
				ls[k].cgpa = ls1[j].cgpa;
				strcpy(ls[k].name, ls1[j].name);
				j++; k++;
			}
		}
	}
	if (i!=l)
	{
		for(; i<l ; i++)
		{
			if(l == s1) {
				ls[k].cgpa = ls1[i].cgpa;
				strcpy(ls[k].name, ls1[i].name);
			}

			else {
				ls[k].cgpa = ls2[i].cgpa;
				strcpy(ls[k].name, ls2[i].name);
			}
			k++;
		}
	}
	if (j!=s)
	{
		for(; j<s ; j++)
		{
			if(l == s1) {
				ls[k].cgpa = ls2[j].cgpa;
				strcpy(ls[k].name, ls2[j].name);
			}
			else {
				ls[k].cgpa = ls1[j].cgpa;
				strcpy(ls[k].name, ls1[j].name);
			}
			k++;
		}
	}	
	
		
}


void mergeSortRec(Element arr[], int s)
{
	if(s>1) {
		int mid = s/2;
		int s1 = mid;
		int s2 = s-mid;
		Element copy1[s1];
		Element copy2[s2];

		for(int i=0; i<s1; i++) {
			copy1[i] = arr[i];
		}

		for(int i=0; i<s2; i++) {
			copy2[i] = arr[i+mid];
		}

		mergeSortRec(copy1, s1);
		mergeSortRec(copy2, s2);
		merge(copy1, s1, copy2, s2, arr);
	}

}

void mergeSortIte(Element arr[], int n) {
	int c;
	int l;

	for(c=1; c<=n-1; c=2*c) {
		for(l=0; l<n-1; l+=2*c) {
			int m = l + c - 1;

			int r;
			if(l+(2*c)-1 > n-1) {
				r = n-1;
			}
			else {
				r = l-1 + (2*c);
			}

			int s1 = m - l + 1;
			int s2 = r - m;

			Element copy1[s1*100];
			Element copy2[s2*100];

			for(int i=0; i<s1; i++) {
				copy1[i] = arr[i];
			}

			for(int i=0; i<s2; i++) {
				copy2[i] = arr[i+m+1];
			}

			mergeSortRec(copy1, s1);
			mergeSortRec(copy2, s2);
			merge(copy1, s1, copy2, s2, arr);
		}
	}
}


void printArr(Element* arr, int s) {
	for(int i = 0; i<s; i++)
	{
		printf("%d. %s: %f\n", i, arr[i].name, arr[i].cgpa);
	}
}
	


int main()
{

	Element *t1 = (Element *) malloc(sizeof(Element)*3000);

	FILE *fp;
	fp = fopen("3000", "r");
	if(fp==NULL) {
		printf("Error while opening file\n");
		exit(1);
	}
	
	int i = 0;
	while(!(feof(fp))) {
		fscanf(fp, "\"%[^,],%f\"\n", t1[i].name, &(t1[i].cgpa));
		i++;
	}
	
	// mergeSortRec(t1, 3000);
	mergeSortIte(t1, 3000);
	
	printArr(t1, 3000);

}	
