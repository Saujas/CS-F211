#include "dns.h"


void readData(Node* root, FILE* fp) {
	int count = 0;
	char s[100];
	char t[100];

	fscanf(fp, "%d\n", &count);

	for(int i = 0; i < count; i++) {
		fscanf(fp, "%[^ ] ", s);
		fscanf(fp, "%[^\n]\n", t);
		readName(root, s, t);
	}
	return;
}


void readName(Node* root, char* s, char* t) {
	char** p;
	p = split(s);
	Node* temp;
	int i = 0;
	while(strlen(p[i])!=0) {
		i++;
	}
	temp = insert(root, p, i-1);
	temp->child = newNode(temp->child);
	strcpy((temp->child)->name, t);
}


Node* newNode(Node* x) {
	x = (Node*) malloc(sizeof(Node));
	return x;
}


Node* insert(Node* root, char** p, int k) {
	Node* temp;
	Node* temp1;
	Node* temp2;
	Node* temp3;
	temp2 = root;
	for(int i = k; i>=0; i--) {
		int c = 0;
		temp = find(temp2->child, p[i]);
		if(temp==NULL) {
			if(temp2->child==NULL) {
				temp1 = newNode(temp1);
				strcpy(temp1->name, p[i]);
				temp2->child = temp1;
				temp2 = temp2->child;
			}
			else {
				temp1 = temp2->child;
				while(temp1!=NULL) {
					temp = find(temp1, p[i]);
					if(temp!=NULL) {
						c = 1;
						temp2 = temp;
						break;
					}
					temp3 = temp1;
					temp1 = temp1->sibling;
				}
				if(c==0) {
					temp1 = newNode(temp1);
					strcpy(temp1->name, p[i]);
					temp2 = temp1;
					temp3->sibling = temp1;
				}
			}
		}
		else {
			temp2 = temp;
		}
	}
	return temp2;
}


Node* find(Node* root, char* s) {
	if(root==NULL) {
		return NULL;
	}
	Node* temp;
	if(strcmp(root->name, s)==0) {
		return root;
	}
	else {
		temp = find(root->child, s);
		if(temp==NULL) {
			return find(root->sibling, s);
		}
	}
}


char **split(char* s) {
	char **a;
	a = (char**) malloc(sizeof(char*)*10);
	int i = 0;
	int j;
	int k;
	for(k = 0; k<10; k++) {
		j = 0;
		a[k] = (char*) malloc(sizeof(char)*100);
		while(i<strlen(s) && s[i]!= '.') {
			a[k][j] = s[i];
			j++;
			i++;
		}
		i++;
	}
	return a;
}


void traverse(Node* root) {
	if(root==NULL) {
		return;
	}
	Node* temp = root;

	while(temp!=NULL) {
		if(temp->name)
            printf("%s\n", temp->name);
        if(temp->child)
            traverse(temp->child);
        temp = temp->sibling;
	}
}


void lookup(Node* root, FILE* fp) {
	char s[100];
	fscanf(fp, "%[^\n]\n", s);
	findName(root, s);
	return;
}


void findName(Node* root, char* s) {
	char** p;
	p = split(s);
	Node* temp;
	int i = 0;
	while(strlen(p[i])!=0) {
		i++;
	}
	temp = locate(root, p, i-1);
	if(temp!=NULL)
		printf("%s\n", temp->name);
	else
		locate1(root, p, i-1);

}


Node* locate(Node* root, char**p, int k) {
	Node* temp;
	Node* temp1;
	int c = 0;
	temp = root->child;
	for(int i = k; i>=0; i--) {
		c = 0;
		if(temp==NULL)
			return NULL;
		temp1 = temp;
		while(temp1!=NULL) {
			if(strcmp(temp1->name, p[i])==0) {
				c=1;
				break;
			}
			temp1 = temp1->sibling;
		}
		if(c==1) {
			temp=temp1->child;
			continue;
		}
		return NULL;
	}
	if(temp->child==NULL)
		return temp;
	return NULL;
}

void locate1(Node* root, char**p, int k) {
	Node* temp;
	Node* temp1;
	int c = 0;
	int count = 0;
	temp = root->child;
	for(int i = k; i>=0; i--) {
		c = 0;
		count = 0;
		if(temp==NULL)
			return;
		temp1 = temp;
		while(temp1!=NULL) {
			count++;
			if(strcmp(temp1->name, p[i])==0) {
				c=1;
				break;
			}
			temp1 = temp1->sibling;
		}
		if(c==1) {
			temp=temp1->child;
			printf("%d ", count);
			continue;
		}
		printf("\n");
		return;
	}
	printf("\n");
	return;
}
