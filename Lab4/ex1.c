#include<stdio.h>

int bits = 0;

void p();
void g();
void h();
void d();

int main() 
{
	printf("\nBits from bits: %u\n", &bits);
	p();
	g();
	h();
	d();
	printf("\nBits from bits at end: %u\n\n", &bits);
}

void p() 
{
	int pilani = 0;
	printf("Pilani %u\n", &pilani);
	p();
	h();
	printf("From pilani\n\n");
}

void g() 
{
	int goa = 0;
	printf("Goa %u\n", &goa);
	
	p();
	printf("From Goa\n\n");
}

void h() 
{
	int hyd = 0;
	printf("Hyd %u\n", &hyd);
}

void d() 
{
	int dub = 0;
	printf("Dubai %u\n", &dub);
	
	g();
	printf("From Dubai\n\n");
}
	

