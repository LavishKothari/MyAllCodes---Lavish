#include<stdio.h>
char e[401];
void printPostfix()
{
	int stack[401],top=-1,i;
	for(i=0;e[i];i++)
	{
		if(e[i]=='(')
			stack[++top]=e[i];
		else if(e[i]>='a' && e[i]<='z')
			printf("%c",e[i]);
		else if(e[i]==')')
		{
			while(stack[top]!='(')
			{
				printf("%c",stack[top]);
				top--;
			}
			top--;
		}
		else 
			stack[++top]=e[i];
	}
	while(top!=-1)
	{
		printf("%c",stack[top]);
		top--;
	}
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",e);
		printPostfix(e);
	}
	return 0;
}
