#include<stdio.h>
void endToBeginning(char str[],int n,int len)
{
	int i,j;
	char temp;
	for(j=0;j<n;j++)
	{
		temp=str[len-1];
		for(i=len-2;i>=0;i--)
			str[i+1]=str[i];
		str[0]=temp;
	}
}
void beginningToEnd(char str[],int n,int len)
{
	int i,j;
	char temp;
	for(j=0;j<n;j++)
	{
		temp=str[0];
		for(i=0;i<len-1;i++)
			str[i]=str[i+1];
		str[len-1]=temp;
	}
}
int main()
{
	int t,n,len;
	char str[10000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&n,str);
		for(len=0;str[len];len++);
		if(n<0)
			endToBeginning(str,-n,len);
		else if(n>0)
			beginningToEnd(str,n,len);
		printf("%s ",str);
	}
}
