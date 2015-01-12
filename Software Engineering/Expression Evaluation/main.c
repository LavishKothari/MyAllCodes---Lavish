#include<string.h>
#include<stdio.h>
#include"header.h"

int main()
{
	char str[100000];
	printf("Enter the expression : ");
	scanf("%[^\n]s",str);
	
	printf("\nAnswer = %lld\n\n",solveExpression(str));
	return 0;
}
