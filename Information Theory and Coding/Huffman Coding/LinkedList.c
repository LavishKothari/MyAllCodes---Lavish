#include<stdlib.h>
#include"LinkedList.h"
struct ListNode*makeNode(struct HuffmanTreeNode*HTNode) // returns newly created node.
{
	struct ListNode*node;
	node=(struct ListNode*)malloc(sizeof(struct ListNode));
	node->HTNode=HTNode;
	node->next=NULL;
	return node;
}
struct ListNode*extractMin(struct ListNode**start) // returns new start
{
	double min;
	struct ListNode*ptr,*minNode;
	min=1.0;
	for(ptr=(*start);ptr;ptr=ptr->next)
	{
		if(ptr->HTNode->p < min)
		{
			minNode=ptr;
			min=ptr->HTNode->p;
		}
	}
	return deleteNode(&start,minNode);
}
struct ListNode*deleteNode(struct ListNode**p2start,struct ListNode*node)
{
	struct ListNode*start;
	start=*p2start;
	if(start==node)
	{
		(*p2start)=(*p2start)->next;
		return start->next;
	}
}
struct ListNode*insertSorted(struct ListNode*start,struct ListNode*newNode)
{
	
}
