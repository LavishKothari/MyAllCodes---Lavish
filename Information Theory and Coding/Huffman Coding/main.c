#include<stdio.h>
#include<stdlib.h>
#include"huffman.h"
int main()
{
	int n,i;
	char *c;
	double*p;
	printf("Enter the number of characters in Domain : ");
	scanf("%d",&n);
	c=(char*)malloc(sizeof(char)*n);
	p=(double*)malloc(sizeof(double)*n);
	printf("Enter the character followed by its probability : \n");
	for(i=0;i<n;i+++)
	{
		printf("Enter character %d, and its probability : ",i+1);
		scanf(" %c%lf",c[i],p[i]);
	}
	printHuffmanCodes(c,p);
	return 0;
}
