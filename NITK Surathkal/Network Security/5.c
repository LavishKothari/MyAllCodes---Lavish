/*
	write a program to implement your own 
		strlen()
		strcpy()
		strcmp()
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int mystrlen(char *str)
{
	int i;
	for(i=0;str[i];i++);
	return i;
}
void mystrcpy(char *a,char*b)
{
	int len,i;
	for(i=0;b[i];i++)
		a[i]=b[i];
	a[i]='\0';
}
int mystrcmp(char *a,char *b)
{
	int i;
	for(i=0;a[i] && b[i];i++)
	{
		//printf("%d\n",i);
		if(a[i]<b[i])
			return -1;
		else if(a[i]>b[i])
			return 1;
	}
	if(b[i])
		return -1;
	if(a[i])
		return 1;
	return 0;
}
int main()
{
	char a[100],b[100],c[100];
	printf("this is a test for strcmp :\n");
	printf("Enter two strings : \n");
	scanf(" %s %s",a,b);
	printf("by library function : %d\n",strcmp(a,b));
	printf("by my function : %d\n\n",mystrcmp(a,b));
	
	printf("This is a test for strlen :\n");
	printf("Enter a string : ");
	scanf(" %s",a);
	printf("Length = %d\n\n",mystrlen(a));
	printf("This is a test for strcpy :\n");
	printf("Enter a string : ");
	scanf(" %s",a);
	strcpy(c,a);
	printf("%s\n",c);
	return 0;
}
