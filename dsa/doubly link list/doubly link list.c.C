#include<stdio.h>
#include<conio.h>

struct Node
{
	int data;
	struct Node*next,*prev;
};

typedef struct Node node;

node*insertafter(node*,node**,int);
node*insertbefore(node*,node**,int);
node*makenode(int);
void forprint(node*);
void revprint(node*);
node*delete(node*,node**);

int main()
{
	node*start,*last,*nn;
	int tmp,c;

	char ch;
	start=NULL;
	last=NULL;

	clrscr();

	while(1)
	{
		printf("ENTER THE DATA PART OF THE NODE...");
		scanf("%d",&tmp);

		if(tmp)
		{
		nn=makenode(tmp);

		if(!start)
			start=last=nn;
		else
		{
			last->next=nn;
			nn->prev=last;
			last=nn;
		}
		}
		else
			break;
		/*printf("DO YOU WANT TO INSERT A NODE? y OR n...");
		scanf(" %c",&ch);    */

	}


	while(1){
	printf("\n");
	clrscr();

	printf("YOU HAVE THE FOLLOWING CHOICES:\n");
	printf("1.INSERT A NODE AFTER A SPECIFIC NODE\n");
	printf("2.INSERT A NODE BEFORE A SPECIFIC NODE\n");
	printf("3.FORWARD PRINTING\n");
	printf("4.REVERSE PRINTING\n");
	printf("5.DELETE A NODE\n");
	printf("6.EXIT\n");


	printf("\nENTER YOUR CHOICE:\n");
	scanf("%d",&c);

	printf("\n");
	switch(c)
	{
		case 1:
		{
			printf("ENTER THE DATA PART OF THE NODE AFTER WHICH YOU WANT TO INSERT YOUR NEW NODE:");
			scanf("%d",&tmp);
			start=insertafter(start,&last,tmp);
		}
		break;

		case 2:
		{
			printf("ENTER THE DATA PART OF THE NODE BEFORE WHICH YOU WANT TO INSERT YOUR NEW NODE:");
			scanf("%d",&tmp);
			start=insertbefore(start,&last,tmp);

		}
		break;

		case 3:
		{
			forprint(start);
			printf("\n");
		}
		break;

		case 4:
		{
			revprint(last);
			printf("\n");
		}
		break;

		case 5:
		{
			start=delete(start,&last);
		}
		break;

		case 6:
			exit(0);
		break;
		default:
		printf("YOU HAVE ENTERED A WRONG CHOICE\n");
	}
	/*
	printf("DO YOU WNAT TO ENTER ANOTHER CHOICE? y OR n: ");
	scanf(" %c",&ch);
	}while(ch=='y');    */
	getch();
	}


	getch();
	return 10;
}



node*makenode(int tmp)
{
	node*nn;
	nn=(node*)malloc(sizeof(node));
	nn->next=NULL;
	nn->prev=NULL;
	nn->data=tmp;
	return nn;
}

void forprint(node*start)
{
	node*ptr;
	if(start)
	{
	for(ptr=start;ptr;ptr=ptr->next)
		printf("%d\t",ptr->data);
	}
	else
		printf("THE LIST IS EMPTY");
}


void revprint(node*last)
{
	node*ptr;
	if(last)
	{
	for(ptr=last;ptr;ptr=ptr->prev)
		printf("%d\t",ptr->data);
	}
	else
		printf("THE LIST IS EMPTY");
}


node*insertafter(node*start,node**p2last,int tmp)
{
	node*nn,*ptr;

	nn=(node*)malloc(sizeof(node));
	nn->prev=nn->next=NULL;


	if(start)
	{

		for(ptr=start;ptr&&ptr->data!=tmp;ptr=ptr->next);
		if(ptr)
		{
			printf("ENTER THE DATA PART OF THE NODE");
			scanf("%d",&nn->data);
			nn->next=ptr->next;
			nn->prev=ptr;
			ptr->next->prev=nn;
			ptr->next=nn;

			if(ptr==*p2last)
				*p2last=nn;
		}
		else
		{
			printf("THE VALUE YOU ENTERED DOES NOT EXIST IN LIST");
		}

	}
	else
		printf("THE VALUE YOU ENTERED DOES NOT EXIST IN LIST");

	return start;
}



node*insertbefore(node*start,node**p2last,int tmp)
{
	node*nn,*ptr;

	nn=(node*)malloc(sizeof(node));
	nn->prev=nn->next=NULL;


	if(start)
	{

		for(ptr=start;ptr&&ptr->data!=tmp;ptr=ptr->next);
		if(ptr)
		{
			printf("ENTER THE DATA PART OF THE NODE");
			scanf("%d",&nn->data);
			nn->next=ptr;
			nn->prev=ptr->prev;
			ptr->prev->next=nn;
			ptr->prev=nn;


			if(ptr==start)
				start=nn;
		}
		else
		{
			printf("THE VALUE YOU ENTERED DOES NOT EXIST IN LIST");
		}
	}
	else
		printf("THE VALUE YOU ENTERED DOES NOT EXIST IN LIST");
	return start;
}

node*delete(node*start,node**p2last)
{
	node*ptr,*prv;
	int sval;
	prv=NULL;
	if(start)
	{
	printf("ENTER THE DATA PART OF THE NODE THAT YOU WANT TO DELETE");
	scanf("%d",&sval);
	for(ptr=start;ptr&&ptr->data!=sval;prv=ptr,ptr=ptr->next);
	if(ptr)
	{
		if(ptr==start)
		{
			start=start->next;
			start->prev=NULL;
		}

		else if(ptr==*p2last)
		{
			*p2last=prv;
			prv->next=NULL;
		}

		else
		{
			ptr->next->prev=prv;
			prv->next=ptr->next;
		}
		free(ptr);
	}
	else
	{
		printf("NO SUCH NODE EXISTS");
	}
	}
	else
		printf("THE LIST IS EMPTY");
	return start;
}