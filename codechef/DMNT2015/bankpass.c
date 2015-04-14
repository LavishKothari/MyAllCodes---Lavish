#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isMatching(char a[],char b[])
{
	int i;
	for(i=0;a[i] && b[i];i++)
		if(a[i]!=b[i])
			return 0;
	return 1;
}
int main()
{
	char **str;
	int n,i,j;
	scanf("%d",&n);
	str=(char**)malloc(sizeof(char*)*n);
	for(i=0;i<n;i++)
	{
		str[i]=(char*)malloc(sizeof(char)*51);
		scanf(" %s",str[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(isMatching(str[i],str[j]))
			{
				printf("vulnerable\n");
				return 0;
			}
		}
	}
	printf("non vulnerable\n");
	return 0;
}
