//PROGRAM FOR QUEUE IMPLEMENTATION USING ARRAYS

#include<stdio.h>
#include<conio.h>

struct Queue
{
	int *arr;
	int max,rear,front;
};

typedef struct Queue queue;

queue getdata(queue);
queue delete(queue);
queue insert(queue,int);

queue getdata(queue q)
{
	printf("ENTER MAXIMUM THE NUMBER OF ELEMENTS : ");
	scanf("%d",&q.max);

	q.arr=(int *)malloc(sizeof(int)*q.max);
	q.front=q.rear=-1;

	return q;
}

queue insert(queue q,int tmp)
{
	if(q.rear==q.max-1)
		printf("overflow");
	else
	{
		//printf("%d",q.rear);
		q.arr[++q.rear]=tmp;
		if(q.rear==0)
			q.front++;
	}
	return q;
}

queue delete(queue q)
{
	if(q.front==-1)
		printf("underflow");
	else
	{
		if(q.front==q.rear)
			q.front=q.rear=-1;
		else
		{
			q.front++;
		}
	}
	return q;
}
void printqueue(queue);

void printqueue(queue q)
{
	int i;
	for(i=q.front;i<=q.rear;i++)
		printf("%d\t",q.arr[i]);
}

int main()
{
	int ch,tmp;
	queue q;
	char choice;
	clrscr();
	q=getdata(q);

	do
	{
		//getdata(q);
		printf("you have the following choices:\n");
		printf("1.insert an element in queue\n");
		printf("2.delete an element from queue\n");
		printf("3.print queue\n");
		printf("\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("enter the data to be inserted in queue:");
				scanf("%d",&tmp);
				q=insert(q,tmp);
			}
			break;
			case 2:
			{
				q=delete(q);
			}
			break;
			case 3:
			{
				printqueue(q);
			}
			break;
			default:
			printf("you have entered a wrong coice:");
		}
		printf("do you want to enter another choice? y or n?");
		scanf(" %c",&choice);
	}while(choice=='y');

	getch();
	return 0;
}





