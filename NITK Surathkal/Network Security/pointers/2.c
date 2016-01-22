/*
	Write functions for the following string operation.
		i. Concatenation. 
		ii. Comparison. 
		iii. Length
		iv. Copy
		v. Reverse.
*/
#include<stdlib.h>
#include<stdio.h>
int mystrlen(char*a)
{
	int i;
	for(i=0;a[i];i++);
	return i;
}
void mystrcpy(char *a,char*b)
{
	int len,i;
	for(i=0;b[i];i++)
		a[i]=b[i];
	a[i]='\0';
}
void reverse(char *a)
{
	char temp;
	int i,j;
	int len=mystrlen(a);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
char *concatenate(char *a,char *b)
{
	char *c;int ci,i;
	int lena=mystrlen(a);
	int lenb=mystrlen(b);
	
	c=(char*)malloc(sizeof(char)*(lena+lenb+1));
	for(i=0;i<lena;i++)
		c[i]=a[i];
	ci=i;
	for(;i<lena+lenb;i++)
		c[i]=b[i-ci];
	c[i]='\0';
	return c;
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
	printf("Enter first string : ");
	scanf(" %[^\n]s",a);
	
	printf("Enter second string : ");
	scanf(" %[^\n]s",b);
	
	printf("the concatenated sting is : %s\n",concatenate(a,b));
	printf("Enter a string to reverse it : ");
	scanf(" %s",a);
	reverse(a);
	printf("the reversed stirng is : %s\n",a);
	return 0;
}
