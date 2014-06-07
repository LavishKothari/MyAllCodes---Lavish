// Doubly LinkList
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node*next,*prev;
};

typedef struct Node Node;

Node*sort2(Node*,Node**);
Node*sort(Node*start,Node**);
void reversePrinting(Node*);
void insertAfter(Node*,Node**,int,int);
Node* insertBefore(Node*,Node**,int,int);
void printList(Node*);
Node*insertLast(Node*,Node**,Node*);
Node*createNode(int);
int search(Node*,int);
Node*Delete(Node*,Node**,int);
Node*deleteLast(Node*,Node**);

int main()
{
	int temp,ch,num;
	Node *newNode,*start,*last;
	start=last=NULL;
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
		printf("8. reverse printing of the list\n");
		printf("9. sort the link list...\n");
		printf("10. sort the link list(another method)...\n");
		printf("11. exit...\n");

		printf("\nenter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("enter the data part of the node that you want to insert :\n");
				scanf("%d",&temp);
				newNode=createNode(temp);
				start=insertLast(start,&last,newNode);
				break;
			case 2:
				printList(start);
				break;
			case 3:
				printf("enter the data that you want to search : ");
				scanf("%d",&temp);
				if(search(start,temp))
					printf("the number you entered was in the list");
				else
					printf("the number you entered was not in the list");
				break;
			case 4:
				printf("enter the data of the node after which you want to insert new node : ");
				scanf("%d",&temp);
				printf("enter the data part of the node that you want to insert : ");
				scanf("%d",&num);
				insertAfter(start,&last,temp,num);
				break;
			case 5:
				printf("enter the data of the node before which you want to insert new node : ");
				scanf("%d",&temp);
				printf("enter the data part of the node that you want to insert : ");
				scanf("%d",&num);
				start=insertBefore(start,&last,temp,num);
				break;
			case 6:
				printf("enter the data part of the node that you want to delete : ");
				scanf("%d",&temp);
				start=Delete(start,&last,temp);
				break;
			case 7:
				if(last==NULL)
				{
					printf("the list is empty...you can't delete any node...");
					break;
				}
				start=deleteLast(start,&last);
				break;
			case 8:
				reversePrinting(last);
				break;
			case 9:
				start=sort(start,&last);
				break;
			case 10:
				start=sort2(start,&last);
				break;
			case 11:
				exit(1);
			default:
				printf("you have entered a wrong choice...enter a valid choice");
		}
	}
}

Node* createNode(int data)
{
	Node*newNode;
	newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=newNode->prev=NULL;
	return newNode;
}

Node*insertLast(Node*start,Node**p2last,Node*newNode)
{
	if(*p2last==NULL)
	{
		*p2last=newNode;
		return newNode;
	}
	(*p2last)->next=newNode;
	newNode->prev=*p2last;
	*p2last=newNode;
	return start;
}

void printList(Node*start)
{
	printf("your list is as follows : \n");
	while(start)
	{
		printf("%d\t",start->data);
		start=start->next;
	}
}

int search(Node*start,int data)
{
	while(start)
	{
		if(start->data==data)
			return 1;
		start=start->next;
	}
	return 0;
}

void insertAfter(Node*start,Node**p2last,int data,int num)
{
	Node*newNode,*tmp;
	newNode=createNode(num);
	if(*p2last==NULL)
		printf("the list is empty...");
	tmp=start;
	while(tmp)
	{
		if(tmp->data==data)
			break;
		tmp=tmp->next;
	}
	if(!tmp)
		printf("the number you enter was not in the list\n");
	else
	{
		newNode->next=tmp->next;
		tmp->next=newNode;
		newNode->prev=tmp;
		if(tmp==*p2last)
		{
			newNode->prev=*p2last;
			*p2last=newNode;
		}
	}
}

Node*insertBefore(Node*start,Node**p2last,int data,int num)
{
	Node*newNode,*tmp;
	newNode=createNode(num);
	if(*p2last==NULL)
	{
		printf("the list is empty...");
		return start;
	}
	if(start->data==data)
	{
		start->prev=newNode;
		newNode->next=start;
		return newNode;
	}
	tmp=start;
	while(tmp)
	{
		if(tmp->data==data)
			break;
		tmp=tmp->next;
	}
	if(!tmp)
		printf("the number you enter was not in the list\n");
	else
	{
		newNode->next=tmp;
		newNode->prev=tmp->prev;
		tmp->prev=newNode;
		newNode->prev->next=newNode;
		if(tmp==*p2last)
		{
			newNode->next=*p2last;
			(*p2last)->prev=newNode;
		}
	}
	return start;	
}

Node*Delete(Node*start,Node**p2last,int data)
{
	Node*ptr;
	for(ptr=start;ptr;ptr=ptr->next)
	{
		if(ptr->data==data)
			break;
	}
	if(!ptr)
	{
		printf("the number you entered was not found in the list...!!!");
		return start;
	}
	if(ptr==start)
	{
		if(start->next==NULL)
		{
			*p2last=NULL;
			return NULL;
		}
		start->next->prev=NULL;
		return start->next;
	}
	if((*p2last)->data != data)
	{
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		return start;
	}
	(*p2last)->prev->next=NULL;
	*p2last=(*p2last)->prev;
	return start;
 }

Node*deleteLast(Node*start,Node**p2last)
{
	return Delete(start,p2last,(*p2last)->data);
}

void reversePrinting(Node*last)
{
	Node*ptr;
	printf("the reverse printing of the list is : \n");
	for(ptr=last;ptr;ptr=ptr->prev)
		printf("%d\t",ptr->data);
}

Node*sort(Node*start,Node**p2last)
{
	Node*ptr,*newNode,*tmp,*start1,*last1;
	start1=last1=NULL;
	while(start!=NULL)
	{
		tmp=ptr=start;
		while(ptr)
		{
			if(tmp->data > ptr->data)
				tmp=ptr;
			ptr=ptr->next;
		}
		newNode=createNode(tmp->data);
		start1=insertLast(start1,&last1,newNode);
		start=Delete(start,p2last,tmp->data);
	}
	*p2last=last1;
	return start1;
}

Node*sort2(Node*start,Node**p2last)
{
	int *arr,count=0,i,tmp,j;
	Node*ptr,*start1,*last1,*newNode;
	ptr=start;
	start1=last1=NULL;
	while(ptr)
	{
		count++;
		ptr=ptr->next;
	}

	arr=(int*)malloc(sizeof(int)*count);
	
	ptr=start;
	for(i=0;i<count;i++)
	{
		arr[i]=ptr->data;	
		ptr=ptr->next;
	}
	
	/* sorting the array bubble */
	for(i=1;i<count;i++)
		for(j=0;j<count-i;j++)
			if(arr[j]>arr[j+1])
			{
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
	
	for(i=0;i<count;i++)
		start1=insertLast(start1,&last1,createNode(arr[i]));
	*p2last=last1;
	return start1;
}