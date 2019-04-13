#include "dns.h"

int main() 
{
	Node* root;
	root = (Node*) malloc(sizeof(Node));
	(root->name)[0] = '\0';
	int x = 0;

	FILE* fp;
	fp = fopen("input.txt", "r");

	if(fp==NULL) {
		printf("File not found\n");
		exit(-1);
	}

	while(x!=-1) {
		fscanf(fp, "%d ", &x);
		switch(x) {
			case 1: readData(root, fp); break;
			case 2: lookup(root, fp); break;
			case -1: break;
			default: break;
		}
	}
	
}