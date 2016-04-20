#include<stdio.h>
int findAnswer(char *str)
{
	int i,counter=0;
	for(i=0;str[i];i++)
	{
		if(str[i]=='(')
			counter++;
		else counter--;
		if(counter<0)
			return 0;
	}
	if(counter==0) return 1;
	return 0;
}
int main()
{
	char str[61];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		if(findAnswer(str))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
