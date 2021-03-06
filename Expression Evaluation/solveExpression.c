#include<stdio.h>
#include<stdlib.h>
#include"header.h"
int getPriority(char c)
{
	if(c=='(')
		return -1;
	if(c=='+' || c=='-')
		return 0;
	if(c=='*' || c=='/' || c=='%')
		return 1;
	if(c=='^')
		return 2;
}

struct LinkedList convertToPostfix(struct LinkedList infix)
{
	struct Node*infixNode;
	struct StackNode*top,*temp;
	struct LinkedList postfix;
	top=NULL;
	postfix.start=NULL;
	for(infixNode=infix.start;infixNode;infixNode=infixNode->next)
	{
		if(infixNode->op=='(')
		{
			top=push(top,makeStackNode(infixNode->op));
			continue;
		}
		if(infixNode->op==')')
		{
			while(top && top->op!='(')
			{
				temp=pop(&top);
				postfix.start=insertAtEnd(postfix.start,makeNode(-2147483647,temp->op));
			}
			pop(&top);
			continue;	
		}
		if(infixNode->op=='\0')
		{
			postfix.start=insertAtEnd(postfix.start,makeNode(infixNode->data,infixNode->op));
		}
		else
		{
			if(top==NULL)
				top=push(top,makeStackNode(infixNode->op));
			else
			{
				if(getPriority(infixNode->op)>getPriority(top->op))
				{
					top=push(top,makeStackNode(infixNode->op));
				}
				else
				{
					while(top && getPriority(infixNode->op) <= getPriority(top->op))
					{
						temp=pop(&top);
						postfix.start=insertAtEnd(postfix.start,makeNode(-2147483647,temp->op));
					}
					top=push(top,makeStackNode(infixNode->op));
				}
				
			}
		}
	}
	while(top)
	{
		temp=pop(&top);
		postfix.start=insertAtEnd(postfix.start,makeNode(-2147483647,temp->op));
	}
	return postfix;
}
int operate(int a,int b,char c)
{
	switch(c)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '%':
			return a%b;
		case '^':
			return (a^b);
	}
	return 0;
}
long long int evaluate(struct LinkedList postfix)
{
	int answer;
	struct Node*ptr,*prev1,*prev2;
	while((postfix.start)->next)
	{
		for(ptr=postfix.start,prev1=NULL,prev2=NULL;ptr && ptr->op=='\0';prev1=prev2,prev2=ptr,ptr=ptr->next);
		answer=operate(prev1->data,prev2->data,ptr->op);
		prev1->data=answer;
		
		prev1->next=ptr->next;
		free(prev2);
		free(ptr);
	}
	return (postfix.start)->data;
}
long long int solveExpression(char str[])
{
	struct LinkedList infix,postfix;
	int i,num;
	infix.start=NULL;
	for(i=0;str[i];)
	{
		if(str[i]==' ')
		{
			i++;
			continue;
		}if(str[i]<='9' && str[i]>='0')
		{
			for(num=0;str[i] && str[i]<='9' && str[i]>='0';i++)
				num=num*10+str[i]-'0';
			infix.start=insertAtEnd(infix.start,makeNode(num,'\0'));
		}
		else
		{
			infix.start=insertAtEnd(infix.start,makeNode(-2147483647,str[i]));
			i++;
		}
	}
	postfix=convertToPostfix(infix);
	return evaluate(postfix);
}