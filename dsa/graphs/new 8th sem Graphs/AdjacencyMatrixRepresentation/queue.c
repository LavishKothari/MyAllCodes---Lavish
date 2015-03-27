#include<stdlib.h>
#include"queue.h"
struct Queue* makeAndInitializeQueue(int n)
{
	struct Queue *q;
	q=(struct Queue*)malloc(sizeof(struct Queue));
	q->numberOfElements=n;
	(q->arr)=(int*)malloc(sizeof(int)*n);
	(q->numberOfElements)=0;
	(q->first)=(q->last)=-1;
	return q;
}
void enqueue(struct Queue*q,int newElement)
{
	if((q->numberOfElements)==0)
		(q->first)++;
	(q->numberOfElements)++;
	(q->arr)[++(q->last)]=newElement;
}
int dequeue(struct Queue*q)
{
	(q->numberOfElements)--;
	if((q->first)==(q->last))
	{
		int r=(q->arr)[q->first];
		(q->first)=(q->last)=-1;
		return r;
	}
	return (q->arr)[(q->first)++];
}
void freeQueue(struct Queue*q)
{
	free(q->arr);
	free(q);
}
