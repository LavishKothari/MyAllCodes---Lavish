#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void printString(char*s,int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%c",s[i]);
	printf("\n");
}
int isPalindrome(char*newStr,int len)
{
	int i,j;
	//printString(newStr,len);
	for(i=0,j=len-1;i<j;i++,j--)
		if(newStr[i]!=newStr[j])
			return 0;
	return 1;
}
int isPalindrome1(char ch,int p,char*str,int len)
{
	int i,flag=0;
	char *newStr;
	//len=strlen(str);
	newStr=(char*)malloc(sizeof(char)*(len+1));
	for(i=0;i<len;i++)
	{
		if(i==p && flag==0)
		{
			newStr[i]=ch;
			i--;
			flag=1;
			continue;
		}
		else if(i<p)
			newStr[i]=str[i];
		if(i>=p)
			newStr[i+1]=str[i];
	}
	if(p==len)
	{
		newStr[len]=ch;
	}
	if(isPalindrome(newStr,len+1))
	{
		free(newStr);
		return 1;
	}
	free(newStr);
	
	return 0;
}
int main()
{
	char ch,str[100001];
	int t,n,j,i,answer,len;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		answer=0;
		len=strlen(str);
		for(i=0;i<len+1;i++)
		{
			//printf("i=%d\n",i);
			for(ch='a';ch<='z';ch++)
			{	
				if(isPalindrome1(ch,i,str,len))
				{
					answer++;
					break;
				}
			}
			//printf("newi=%d\n",i);
		}
		printf("%d\n",answer);
	}
	return 0;
}
