#include"linkedlist.h"
struct Node*makeNode(struct Vertex*vertex)
{
	struct Node*node;
	node=(struct Node*)malloc(sizeof(struct Node));
	node->data=vertex;
	node->next=NULL;
	return node;
}
void add(struct LinkedList*list,struct Node*node)
{
	(list->last)->next=node;
	(list->last)=(list->last)->next;
}
void remove(struct Lin)
