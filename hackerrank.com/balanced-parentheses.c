#include<stdio.h>
#include<string.h>
char str[1001];
char stack[1001];
int findAnswer()
{
	int i,ind=0;
	if(strlen(str)==1)
		return 0;
	for(i=0;str[i];i++)
	{
		if(str[i]=='{' || str[i]=='[' || str[i]=='(')
			stack[ind++]=str[i];
		else 
		{
			ind--;
			if(str[i]=='}' && stack[ind]!='{')
				return 0;
			if(str[i]==']' && stack[ind]!='[')
				return 0;
			if(str[i]==')' && stack[ind]!='(')
				return 0;
		}
	}
	if(ind==0)
		return 1;
	return 0;
		
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		if(findAnswer())
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
