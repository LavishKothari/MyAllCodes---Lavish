#include<stdlib.h>
#include"queue.h"
struct Queue* createQueue(int elementSize)
{
	struct Queue *q;
	q=(struct Queue*)malloc(sizeof(struct Queue));
	q->list=createList(elementSize);
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
	/* here you need to delete the first element of the queue. */
	if(q->list->start)
	{
	    node=q->list->start;
	    q->list->start=q->list->start->next;
	    return node;
	}
	else 
	    return NULL;
}
void freeQueue(struct Queue*q)
{
	free(q);
}
