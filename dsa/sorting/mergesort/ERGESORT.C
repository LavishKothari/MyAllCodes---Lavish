//MERGE SORT
//SORTING A LINK LIST
//RECURSIVE DEFINITION
//BY LAVISH KOTHARI

#include<stdio.h>
#include<conio.h>

struct Node
{
	int val;
	struct Node*next;
};

typedef struct Node node;

void printlist(node*);
node*makenode(int);
node*mergesort(node*);
node*divide(node*);
node*merge(node*,node*);

int main()
{
	int i,tmp;
	node*start,*nn,*last;
	clrscr();
	start=last=NULL;

	while(1)
	{
		printf("enter the data part of the node:");
		scanf("%d",&tmp);

		if(tmp==0)
			break;

		nn=makenode(tmp);

		if(start)
		{
			last->next=nn;
			last=nn;
		}
		else
		{
			start=last=nn;
		}
	}
	start=mergesort(start);

	printlist(start);
	getch();
	return 1;
}


node*mergesort(node*start)
{
	node*nh;
	if(start&&start->next)
	{

		nh=divide(start);
		start=mergesort(start);
		nh=mergesort(nh);
		start=merge(start,nh);
	}
	return start;
}

node*divide(node*start)
{
	node*ptr1,*ptr2,*start2=NULL;
	if(start->next)
	{
		ptr1=start;
		ptr2=start->next->next;
		while(ptr2)
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next;
			if(ptr2)
				ptr2=ptr2->next;
		}
		start2=ptr1->next;
		ptr1->next=NULL;
	}
	return start2;
}

node*merge(node*s1,node*s2)
{
	node*s3,*l3,*tmp;
	s3=l3=NULL;
	while(s1&&s2)
	{
		if(s1->val<s2->val)
		{
			tmp=s1;
			s1=s1->next;
		}
		else
		{
			tmp=s2;
			s2=s2->next;
		}
		if(!s3)
			s3=tmp;
		else
			l3->next=tmp;
		l3=tmp;
	}
	if(s1)
	{
		if(!s3)
			s3=s1;
		else
			l3->next=s1;
	}
	if(s2)
	{
		if(!s3)
			s3=s2;
		else
			l3->next=s2;
	}
	return s3;
}


void printlist(node*start)
{
	while(start)
	{
		printf("%d\t",start->val);
		start=start->next;
	}
}


node*makenode(int tmp)
{
	node*nn;
	nn=(node*)malloc(sizeof(node));
	nn->val=tmp;
	nn->next=NULL;
	return nn;
}

