#include"header.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct Node*makeNode(int data,char op)
{
	struct Node*newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node*));
	newNode->data=data;
	newNode->op=op;
	newNode->next=NULL;
	return newNode;
}

struct Node*insertAtEnd(struct Node*start, struct Node*newNode)
{
	struct Node*currentNode;
	if(!start)
		return newNode;
	for(currentNode=start;currentNode->next;currentNode=currentNode->next);
	currentNode->next=newNode;
	return start;
}

struct Node*deleteNode(struct Node*start,int data,char op)
{
	struct Node*currentNode,*prevNode=NULL,*temp,*prev;
	for(prevNode=NULL,currentNode=start;;prevNode=currentNode,currentNode=currentNode->next)
	{
		if(currentNode->data==data && currentNode->op==op)
			break;
	}
	if(currentNode==start)
	{
		temp=start;
		start=start->next;
		free(temp);
	}
	else
	{
		prev->next=currentNode->next;
		free(currentNode);
	}
	return start;
}

void printList(struct Node*start)
{
	while(start)
	{
		if((start->op)!='\0')
			printf("%c\n",start->op);
		else
			printf("%d\n",start->data);
		start=start->next;
	}
	printf("\n");
}
