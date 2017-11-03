#include<stdio.h>
#include<stdlib.h>
bool isSubString(char *str)
{
	for(int i=0;str[i];i++)
		if(str[i] && str[i+1] && str[i+2] && str[i+3] && str[i+4] && (str[i]=='S'|| str[i]=='s') && (str[i+1]=='P' || str[i+1]=='p') && (str[i+2]=='O' || str[i+2]=='o') && (str[i+3]=='O' || str[i+3]=='o') && (str[i+4]=='N' || str[i+4]=='n'))
			return true;
	return false;
}
bool findAnswer(char**str,int r,int c)
{
	for(int i=0;i<r;i++)
		if(isSubString(str[i]))
			return true;

	char**nstr=(char **)malloc(sizeof(char*)*c);
	for(int i=0;i<c;i++)
		nstr[i]=(char*)malloc(sizeof(char)*(r+1));
	for(int i=0;i<c;i++)
	{
		int j;
		for(j=0;j<r;j++)
			nstr[i][j]=str[j][i];
		nstr[i][j]='\0';
	}

	for(int i=0;i<c;i++)
		if(isSubString(nstr[i]))
			return true;
	return false;
}
int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		char **str;
		str=(char **)malloc(sizeof(char*)*r);
		for(int i=0;i<r;i++)
			str[i]=(char*)malloc(sizeof(char)*(c+1));
		for(int i=0;i<r;i++)
			scanf(" %s",str[i]);
		if(findAnswer(str,r,c))
			printf("There is a spoon!\n");
		else printf("There is indeed no spoon!\n");
	}
	return 0;
}
