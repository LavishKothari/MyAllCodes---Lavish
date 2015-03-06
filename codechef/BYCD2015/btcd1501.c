#include<stdio.h>
#include<stdlib.h>
int isSubstring(char str[],char subStr[])
{
	int i,j,ci;
	for(i=0;str[i];i++)
	{
		ci=i;
		for(j=0;subStr[j] && str[i];j++,i++)
		{
			if(subStr[j]==str[i])
				continue;
			else break;
		}
		if(!subStr[j])
			return 1;
		i=ci;
	}
	return 0;
}
char *findStr(int n)
{
	char str[10],*newStr,i,j;
	int counter=0;
	newStr=(char*)malloc(sizeof(char)*10);
	if(n==0)
	{
		newStr[0]='a';
		newStr[1]='\0';
		return newStr;
	}
	while(n)
	{
		str[counter++]=n%26+'a';
		n/=26;
	}
	for(i=counter-1,j=0;i>=0;j++,i--)
		newStr[j]=str[i];
	newStr[j]='\0';
	return newStr;
}
int main()
{
	int t,counter;
	char str[100001],*temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		counter=0;
		while(1)
		{
			temp=findStr(counter);
			if(!isSubstring(str,temp))
			{
				printf("%s\n",temp);
				break;
			}
			counter++;
		}
	}
	return 0;
}
