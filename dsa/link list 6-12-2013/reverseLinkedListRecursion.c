#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node*next;
};
struct Node*head;
struct Node*makeNode(int data)
{
	struct Node*node;
	node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->next=NULL;
	return node;
}
struct Node*insert(struct Node*start,struct Node*newNode)
{
	struct Node*ptr;
	if(start==NULL)
		return newNode;
	for(ptr=start;ptr->next;ptr=ptr->next);
	ptr->next=newNode;
	return start;
}
void printList(struct Node*start)
{
	struct Node*ptr;
	for(ptr=start;ptr;ptr=ptr->next)
		printf("%d ",ptr->data);
	printf("\n");
}
struct Node* reverseWithReturn(struct Node*node)
{
	struct Node*temp;
	if(node==NULL)
		return NULL;
	if(node->next==NULL)
		return node;
	temp=reverseWithReturn(node->next);
	node->next->next=node;
	node->next=NULL;
	return temp;
}
void reverseWithoutReturn(struct Node*node)
{
	/**
		for this function we need to maintain a global head
		this global head will be the head of new reversed list.

		this function will update the variable head
		now the head variable will store the start of newly formed list.
	*/
	if(node==NULL)
		return;
	if(node->next==NULL)
	{
		head=node;
		return ;
	}
	reverseWithoutReturn(node->next);
	node->next->next=node;
	node->next=NULL;
}
void reversePrint(struct Node*node)
{
	if(node==NULL)
		return;
	reversePrint(node->next);
	printf("%d ",node->data);
}
int main()
{
	struct Node*start;
	start=NULL;
	start=insert(start,makeNode(5));
	start=insert(start,makeNode(6));
	start=insert(start,makeNode(5));
	start=insert(start,makeNode(3));
	start=insert(start,makeNode(51));
	start=insert(start,makeNode(9));
	start=insert(start,makeNode(78));

	printList(start);
	start=reverseWithReturn(start);
	printList(start);

	return 0;
}
