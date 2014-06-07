#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node*next;
};


typedef struct node node;

node*makenode(int);
void printlist(node*);
node*push(node*,node**,node*);
node*pop(node*,node**);

int main()
{
	int i,num,ch;

	node*start,*last,*nn;
	nn=last=start=NULL;
	clrscr();
	printf("CREATE YOUR STACK\n");
	while(1)
	{
		printf("ENTER THE DATA PART OF THE NODE :  ");
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

	while(1)
	{
	printf("\nYOU HAVE THE FOLLOWING CHOICES : \n");
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.PRINT THE LIST\n");
	printf("4.EXIT\n");
	printf("\nENTER YOUR CHOICE : ");
	scanf(" %d",&ch);

	switch(ch)
	{
		case 1:
			printf("ENTER THE VALUE YOU WANT TO PUSH INSIDE YOUR STACK : ");
			scanf("%d",&num);
			nn=makenode(num);
			start=push(start,&last,nn);
			break;
		case 2:
			start=pop(start,&last);
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
	nn->data=num;
	nn->next=NULL;
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

node*push(node*start,node**p2last,node*nn)
{
	if(start==NULL)
	{
		start=(*p2last)=nn;
		return start;
	}
	(*p2last)->next=nn;
	(*p2last)=nn;
	printf("\nELEMENT PUSHED SUCCESSFULLY...\n");
	return start;
}

node*pop(node*start,node**p2last)
{
	node*tmp,*ptr;
	tmp=(*p2last);
	ptr=start;
	if(start==NULL)
	{
		printf("\nUNDER-FLOW\n");
		return start;
	}

	if(start==(*p2last))
	{
		start=(*p2last)=NULL;
		return start;
	}

	while(1)
	{
		if(ptr->next==(*p2last))
			break;
		ptr=ptr->next;
	}


	(*p2last)=ptr;
	(*p2last)->next=NULL;

	free(tmp);
	printf("\nELEMENT POPPED SUCCESSFULLY...\n");

	return start;
}