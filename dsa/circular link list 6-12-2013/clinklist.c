// Circular Link List
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node*next;
};

typedef struct Node Node;

Node*createNode(int);
Node*insertLast(Node*,int);
void printList(Node*);
int search(Node*,int);
Node*insertAfter(Node*,int,int);
Node*insertBefore(Node*,int,int);
Node*Delete(Node*,int);
Node*deleteLast(Node*);
Node*reverseList(Node*);
Node*sort(Node*);
int countNodes(Node*);

int main()
{
	int ch,tmp,n;
	Node*start;
	start=NULL;

	while(1)
	{
		printf("\n_________________menu__________________\n");
		printf("1. insert at the end of list...\n");
		printf("2. print the list...\n");
		printf("3. search a speific item...\n");
		printf("4. insert after a specific node...\n");
		printf("5. insert a node before a specific node...\n");
		printf("6. delete a specific node...\n");
		printf("7. delete a last node...\n");
		printf("8. reverse the list...\n");
		printf("9. sort the link list...\n");
		printf("10. count the total number of node in the list...\n");
		printf("11. exit...\n");

		printf("\nenter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("enter the data part of the node that you want to insert... : ");
				scanf("%d",&tmp);
				start=insertLast(start,tmp);
				break;
			case 2:
				printList(start);
				break;
			case 3:
				printf("enter the data item that you want to search : ");
				scanf("%d",&tmp);
				if(search(start,tmp))
					printf("the data you entered was found in the list...");
				else
					printf("the data you entered was not found in the list...");
				break;
			case 4:
				printf("enter the data part of the node after which you want to insert new node");
				scanf("%d",&n);
				printf("enter the data part of the node that you want to insert : ");
				scanf("%d",&tmp);
				start=insertAfter(start,n,tmp);
				break;
			case 5:
				printf("enter the data part of the node before which you want to insert new node");
				scanf("%d",&n);
				printf("enter the data part of the node that you want to insert : ");
				scanf("%d",&tmp);
				start=insertBefore(start,n,tmp);
				break;
			case 6: 
				printf("enter the data part of the node that you want to delete...");
				scanf("%d",&tmp);
				start=Delete(start,tmp);
				break;
			case 7:
				start=deleteLast(start);
				break;
			case 8:
				start=reverseList(start);
				break;
			case 9:
				start=sort(start);
				break;
			case 10:
				printf("the total number of nodes are : %d",countNodes(start));
				break;
			case 11:
				exit(1);
			default:
				printf("you have entered a wrong choice !!!!");
		}
	}
	return 0;
}

Node*createNode(int data)
{
	Node*newNode;
	newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

Node*insertLast(Node*start,int data)
{
	Node*newNode,*ptr;
	newNode=createNode(data);
	if(start==NULL)
	{
		newNode->next=newNode;
		return newNode;
	}
	for(ptr=start;ptr->next!=start;ptr=ptr->next);
	newNode->next=start;
	ptr->next=newNode;
	return start;
}

void printList(Node*start)
{
	Node*ptr;
	ptr=start;
	if(start)
		do
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}while(ptr!=start);
}

int search(Node*start,int data)
{
	Node*ptr=start;
	if(!start)
		return 0;
	do
	{
		if(ptr->data==data)
			return 1;
		ptr=ptr->next;
	}while(ptr!=start);
	return 0;
}

Node*insertAfter(Node*start,int data,int tmp)
{
	Node *ptr,*newNode;
	newNode=createNode(tmp);
	ptr=start;
	if(!start)
	{
		printf("the list is empty...");
		return start;
	}
	
	do
	{
		if(ptr->data==data)
			break;
		ptr=ptr->next;
	}while(ptr->next!=start);

	if(ptr->next==start && ptr->data==data)
	{
		ptr->next=newNode;
		newNode->next=start;
		return start;
	}
	if(ptr->next==start && ptr==start)
	{
		ptr->next=newNode;
		newNode->next=start;
		return start;
	}
	newNode->next=ptr->next;
	ptr->next=newNode;
	return start;
}

Node*insertBefore(Node*start,int data,int tmp)
{
	Node *ptr,*newNode,*prev,*temp;
	newNode=createNode(tmp);
	ptr=start;
	if(!start)
	{
		printf("the list is empty");
		return start;
	}
	do
	{
		if(ptr->data==data)
			break;
		prev=ptr;
		ptr=ptr->next;
	}while(ptr->next!=start);
	
	if(ptr->next==start)
	{
		if(ptr->data==data)
		{
			prev->next=newNode;
			newNode->next=ptr;
			return start;
		}
		printf("number you entered is not in the list");
		return start;
	}

	if(ptr->next==start && ptr==start) /*this is the condition for only one node in the list*/
	{
		newNode->next=ptr;
		ptr->next=newNode;
		return newNode;
	}
	
	if(ptr==start && ptr->data==data)
	{
		newNode->next=start;
		temp=start;
		for(temp=start;temp->next!=start;temp=temp->next);
		temp->next=newNode;
		return newNode;
	}
	newNode->next=ptr;
	prev->next=newNode;
	return start;
}

Node*Delete(Node*start,int data)
{
	Node*ptr,*prev,*tmp;
	prev=NULL;
	ptr=start;
	if(!start)
	{
		printf("the list is empty...");
		return start;
	}
	for(ptr=start;ptr->next!=start;prev=ptr,ptr=ptr->next)
	{
		if(ptr->data==data)
			break;
	}
	if(ptr->next==start)
	{
		if(ptr->data==data && ptr==start)
		{
			return NULL;
		}

		if(ptr->data==data)
		{
			prev->next=ptr->next;
			return start;
		}
		printf("the data value you entered was not found in the list...");
		return start;
	}
	if(prev==NULL)
	{
		for(tmp=start;tmp->next!=start;tmp=tmp->next);
		tmp->next=start->next;
		return start->next;
	}
	prev->next=ptr->next;
	return start;	
}

Node*deleteLast(Node*start)
{
	Node*tmp;
	for(tmp=start;tmp->next!=start;tmp=tmp->next);
	return Delete(start,tmp->data);	
}

Node*reverseList(Node*start)
{
	Node*tmp,*start1;
	start1=NULL;
	if(!start)
	{
		printf("the list is empty...");
		return start;
	}
	while(start)
	{
		for(tmp=start;tmp->next!=start;tmp=tmp->next);
		start1=insertLast(start1,tmp->data);
		start=deleteLast(start);	
	}
	return start1;
}

Node*sort(Node*start)
{
	Node*tmp,*ptr,*start1;
	start1=NULL;
	while(start)
	{
		for(tmp=start,ptr=start;tmp->next!=start;tmp=tmp->next)
		{
			if(ptr->data > tmp->data)
				ptr=tmp;
		}
		/*now ptr contains the address of that node that has minimum data part */
		start1=insertLast(start1,ptr->data);
		start=Delete(start,ptr->data);
	}
	return start1;
}

int countNodes(Node*start)
{
	Node*ptr;
	int counter=0;
	if(!start)
		return 0;
	for(ptr=start;ptr->next!=start;ptr=ptr->next)
		counter++;
	return counter+1;
}