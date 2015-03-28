#include<stdlib.h>
#include<string.h>
#include"LinkedList_Generic.h"

struct LinkedList_Generic *makeAndInitialiseLinkedList(int elementSize)
{
	struct LinkedList_Generic *list;
	list=(struct LinkedList_Generic*)malloc(sizeof(struct LinkedList_Generic));
	list->start=NULL;
	list->elementSize=elementSize;
	return list;
}
struct ListNode_Generic *makeAndInitialiseListNode(struct LinkedList_Generic *list,void*element)
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
void removeElement(struct LinkedList_Generic*list,int ide,int(*getId)(struct ListNode_Generic*))
{
	struct ListNode_Generic*ptr,*prev;
	for(ptr=(list->start),prev=NULL;ptr && (*getId)(ptr)!=ide;prev=ptr,ptr=ptr->next);
	if(prev!=NULL)
	{
		prev->next=ptr->next;
		free(ptr->data);
		free(ptr);
	}
	else if(prev==NULL && ptr!=NULL) // means the element that we need to delete is the start of the list.
		(list->start)=((list->start)->next);
}
