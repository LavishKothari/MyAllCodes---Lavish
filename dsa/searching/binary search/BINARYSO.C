//BINARY SEARCH (AFTER SORTING THE ARRAY INPUTED BY USER)
//MADE BY LAVISH KOTHARI
//23-02-2013
//17:37:21


#include<stdio.h>
#include<conio.h>

void sort(int*,int);
void bsearch(int *,int,int);
int main()
{
	int *arr,n,i,sval;
	clrscr();
	printf("ENTER THE NUMBER OF ELEMENTS OF ARRAY\n");
	scanf("%d",&n);

	printf("ENTER THE DATA OF ARRAY:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("ENTER THE SEARCH VALUE:\n");
	scanf("%d",&sval);

	sort(arr,n);

	bsearch(arr,n,sval);

	getch();
	return 1;
}

void sort(int *arr,int n)
{
	int i,j,tmp;
	for(i=1;i<n;i++)
	for(j=0;j<n-i;j++)
	if(arr[j]>arr[j+1])
	{
		tmp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=tmp;
	}
}

void bsearch(int *arr,int n,int sval)
{
	int i,j,mid,flag=0;
	i=0;j=n-1;
	mid =(i+j)/2;

	while(i<=j)
	{
		if(arr[mid]==sval)
		{
			flag=1;
			break;
		}

		else
		{
			if(sval>arr[mid])
				i=mid+1;
			else
				j=mid-1;
		}
		mid=(i+j)/2;
	}

	if(flag==0)
		printf("SEARCH VALUE NOT FOUND");
	else
		printf("SEARCH VALUE FOUND IN LIST");
}





















