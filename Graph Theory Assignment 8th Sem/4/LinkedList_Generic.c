#include<stdlib.h>
#include<string.h>
#include"LinkedList_Generic.h"

struct LinkedList_Generic *createList(int elementSize)
{
	struct LinkedList_Generic *list;
	list=(struct LinkedList_Generic*)malloc(sizeof(struct LinkedList_Generic));
	list->start=NULL;
	list->elementSize=elementSize;
	return list;
}
struct ListNode_Generic *createNode(struct LinkedList_Generic *list,void*element)
{
	struct ListNode_Generic*listNode;
	listNode=(struct ListNode_Generic*)malloc(sizeof(struct ListNode_Generic));
	listNode->data=element;
	//listNode->data=malloc(sizeof(list->elementSize));
	//memcpy(listNode->data,element,list->elementSize);
	listNode->next=NULL;
	return listNode;
}
void addElement(struct LinkedList_Generic*list,struct ListNode_Generic*element)
{
	struct ListNode_Generic*ptr,*prev;
	if((list->start)==NULL)
		(list->start)=element;
	else
	{
		for(ptr=(list->start);ptr;prev=ptr,ptr=ptr->next);
		(prev->next)=element;
	}
}
void removeElement(struct LinkedList_Generic*list,struct ListNode_Generic*node)
{
	struct ListNode_Generic*ptr,*prev;
	for(ptr=(list->start),prev=NULL;ptr && (ptr)!=node;prev=ptr,ptr=ptr->next);
	if(ptr)
	{
		if(prev!=NULL)
		{
			prev->next=ptr->next;
			if(ptr)
			{
				free(ptr);
			}
		}
		else if(prev==NULL && ptr!=NULL) // means the element that we need to delete is the start of the list.
		{
			prev=list->start;
			(list->start)=((list->start)->next);
			if(prev)
			{
				free(prev);
			}
		}
	}
}
struct ListNode_Generic*getNodeReferenceWithGivenData(struct LinkedList_Generic*list,void*data)
{
	struct ListNode_Generic*node;
	for(node=list->start;node;node=node->next)
	{
		if((node->data)==data)
			return node;
	}
}
