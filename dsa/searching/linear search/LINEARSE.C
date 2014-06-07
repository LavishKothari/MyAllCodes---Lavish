#include<stdio.h>
#include<conio.h>

void lsearch(int *,int,int);

int main()
{
	int *arr,n,i,sval;
	clrscr();

	printf("ENTER THE NUMBER OF ELEMENTS OF ARRAY:\n");
	scanf("%d",&n);

	printf("ENTER THE DATA OF ARRAY:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("ENTER THE SEARCH VALUE:\n");
	scanf("%d",&sval);

	lsearch(arr,n,sval);

	getch();
	return 1;
}

void lsearch(int *arr,int n,int sval)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==sval)
		{
			flag=1;
			break;
		}
	}
	if(flag)
		printf("VALUE FOUND AT POSITION = %d\n",(i+1));
	else
		printf("VALUE NOT FOUND\n");
}




