/*
	The queue is implemented using the concept of generic linked list.
*/
#include"LinkedList_Generic.h"
struct Queue
{
	struct LinkedList_Generic *list;
	int numberOfElements;
};

struct Queue* createQueue(int elementSize);
void enqueue(struct Queue*q,struct ListNode_Generic*node);
struct ListNode_Generic* dequeue(struct Queue*q);
void freeQueue(struct Queue*);
