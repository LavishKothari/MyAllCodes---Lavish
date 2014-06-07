#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node*next;
};
typedef struct node node;

void printlist(node*);
node*makenode(int);
node*insert(node*,node**,node*);
node*delete_node(node*,node**,node*);

int main()
{

	int num,ch;
	node*start,*last,*nn;
	clrscr();
	start=last=nn=NULL;
	while(1)
	{
		printf("ENTER THE DATA OF QUEUE : \n");
		scanf("%d",&num);

		if(num==0)
			break;

		nn=makenode(num);
		if(start==NULL)
		{
			start=last=nn;
		}
		else
		{
			last->next=nn;
			last=nn;
		}
	}

	clrscr();
	while(1)
	{
	printf("\nYOU HAVE THE FOLLOWING CHOICES : \n");
	printf("1.INSERT AN ELEMENT IN QUEUE\n");
	printf("2.DELETE AN ELEMENT FROM QUEUE\n");
	printf("3.DISPLAY THE ELEMENTS OF THE QUEUE\n");
	printf("4.EXIT\n");
	printf("\nENTER YOUR CHOICE : ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			printf("ENTER THE DATA PART OF THE NODE THAT YOU WANT TO INSERT : \n");
			scanf("%d",&num);
			nn=makenode(num);
			start=insert(start,&last,nn);
			break;
		case 2:
			start=delete_node(start,&last,nn);
			break;
		case 3:
			printlist(start);
			break;
		case 4:
			exit(1);
		default:
			printf("YOU HAVE ENTERED A WRONG CHOICE\n");

	}
	printf("\n\nPRESS ANY KEY TO CONTINUE...\n");
	getch();
	clrscr();
	}

	getch();
	return 1;
}



node*makenode(int num)
{
	node*nn;
	nn=(node*)malloc(sizeof(node));
	nn->next=NULL;
	nn->data=num;
	return nn;
}


void printlist(node*start)
{
	while(start)
	{
		printf("%d\t",start->data);
		start=start->next;
	}
}


node*insert(node*start,node**p2last,node*nn)
{
	if(start)
	{
		(*p2last)->next=nn;
		(*p2last)=nn;
		return start;
	}
	start=(*p2last)=nn;
	return start;
}

node*delete_node(node*start,node**p2last,node*nn)
{
	node*tmp;
	tmp=start;
	if(!start)
	{
		printf("\nUNDER-FLOW\n");
		return start;
	}
	if(start==(*p2last))
	{
		start=(*p2last)=NULL;
		return start;
	}
	start=start->next;
	free(tmp);
	return start;
}
