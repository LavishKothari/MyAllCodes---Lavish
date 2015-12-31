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
	len=mystrlen(b);
	a=malloc(sizeof(char)*len);
	for(i=0;b[i];i++)
		a[i]=b[i];
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
	char a[100],b[100];
	printf("Enter two strings : \n");
	scanf("%s %s",a,b);
	printf("by library function : %d\n",strcmp(a,b));
	printf("by my function : %d\n",mystrcmp(a,b));
	
	return 0;
}
