
//IMPLEMENTATION OF STACKS USING ARRAYS


#include<stdio.h>
#include<conio.h>

int max;
int top=-1;
int *a;
void printstack();
int pop();
void push(int);

int main()
{
	int k,ch,num;
	clrscr();
	printf("ENTER THE MAXIMUM NUMBER OF ELEMENTS : ");
	scanf("%d",&max);

	a=(int *)malloc(sizeof(int)*max);

	while(1)
	{
		printf("YOU HAVE THE FOLLOWING CHOICES : \n");
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.DISPLAY THE CONTENTS OF THE STACK : \n");
		printf("4.EXIT\n");
		printf("ENTER YOUR CHOICE : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("ENTER THE VALUE YOU WANT TO PUSH : ");
			scanf("%d",&num);
			push(num);

			break;

			case 2:
			pop();
			break;

			case 3:
			printstack();
			break;

			case 4:
			exit(1);

			default:
			printf("YOU HAVE ENTERED A WRONG CHOICE...\n");
		}
		printf("\n\nPRESS ANY KEY TO CONTINUE...\n");
		getch();
		clrscr();
	}

	k=pop();
	printf("%d\n",k);
	k=pop();
	printf("%d",k);

	getch();
	return 1;
}

void push(int tmp)
{
	if(top==max-1)
		printf("OVERFLOW");
	else
		a[++top]=tmp;
	printf("VALUE PUSHED SUCCESSFULLY IN STACK\n");
}

int pop()
{
	if(top==-1)
	{
		printf("UNDERFLOW");
		return 1;
	}
	else
		return a[top--];
}

void printstack()
{
	int i;

	for(i=top;i>=0;i++)
	{
		printf("%d\n",a[i]);
	}
}
