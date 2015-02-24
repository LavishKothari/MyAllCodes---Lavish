#include<stdio.h>
char stack[10000];
int top=-1;
void print();
void push(char a)
{
	stack[++top]=a;
}
char pop()
{
	return stack[top--];
}
int main()
{
	int t,i;
	char str[10000];
	scanf("%d",&t);
	while(t--)
	{
		top=-1;
		scanf(" %[^\n]s",str);
		for(i=0;str[i];i++)
		{
			if(str[i]=='(' || str[i]=='{' || str[i]=='[' || str[i]=='<')
				push(str[i]);
			else if(str[i]==')' || str[i]==']' || str[i]=='}' || str[i]=='>')
			{
				if((stack[top]=='<' && str[i]=='>') || (stack[top]=='{' && str[i]=='}') || (stack[top]=='[' && str[i]==']') || (stack[top]=='(' && str[i]==')') )
					pop();
				else
					break;
			}
		}
		if(str[i] || top!=-1)
			printf("0 ");
		else printf("1 ");
	}
	return 0;
}
