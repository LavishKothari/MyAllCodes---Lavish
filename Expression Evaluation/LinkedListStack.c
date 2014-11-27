#include"header.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct StackNode*makeStackNode(char op)
{
	struct StackNode*newNode;
	newNode=(struct StackNode*)malloc(sizeof(struct StackNode*));
	newNode->op=op;
	newNode->next=NULL;
	return newNode;
}

struct StackNode*push(struct StackNode*top, struct StackNode*newNode)
{
	if(!top)
		return newNode;
	newNode->next=top;
	return newNode;
}

struct StackNode*pop(struct StackNode**top)
{
	struct StackNode*returnNode;
	if(!(*top))
		return NULL;
	returnNode=(*top);
	*top=(*top)->next;
	return returnNode;
}

