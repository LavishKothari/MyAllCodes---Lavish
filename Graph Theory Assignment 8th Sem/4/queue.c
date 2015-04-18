#include<stdlib.h>
#include"queue.h"
struct Queue* makeAndInitializeQueue(int elementSize)
{
	struct Queue *q;
	q=(struct Queue*)malloc(sizeof(struct Queue));
	q->list=makeAndInitialiseLinkedList(elementSize);
	return q;
}
void enqueue(struct Queue*q,struct ListNode_Generic*node)
{
	(q->numberOfElements)++;
	addElement(q->list,node);
}
struct ListNode_Generic* dequeue(struct Queue*q)
{
	struct ListNode_Generic*node,*prevNode;
	prevNode=NULL;
	(q->numberOfElements)--;
	
	for(node=q->list->start;node && node->next;prevNode=node,node=node->next);
	if(prevNode==NULL)
	{
		if(node==NULL)
			return NULL;
		else if(node->next==NULL)
		{
			node=q->list->start;
			q->list->start=NULL;
			return node;
		}
	}
	else if(prevNode)
		prevNode->next=NULL;
	return node;
}
void freeQueue(struct Queue*q)
{
	free(q);
}
