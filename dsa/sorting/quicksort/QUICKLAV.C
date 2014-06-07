#include<stdio.h>
#include<conio.h>


void quicksort(int *,int,int);
int qsort(int*,int,int);

int flag=0,abc;

int main()
{
	int i,j,ploc,min,n,arr[50];
	clrscr();

	printf("enter the max no of elements of array\n");
	scanf("%d",&n) ;
	abc=n;

	printf("enter the data of array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	quicksort(arr,0,n-1);


	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);

	getch();
	return 1;
}


void quicksort(int*arr,int min,int max)
{
	int ploc;
	while(max>min)
	{
		ploc=qsort(arr,min,max);
		quicksort(arr,min,ploc-1);
		quicksort(arr,ploc+1,max);
		if(flag>abc)
			return;
	}
}


int qsort(int *arr,int min,int max)
{
	int ploc,j,tmp;
	ploc=min;
	for(j=ploc+1;j<=max;)
		if(arr[j]<arr[min])
		{
			ploc++;
			tmp=arr[ploc];
			arr[ploc]=arr[j];
			arr[j]=tmp;
			j=ploc+1;
		}
		else
			j++;


	tmp=arr[min];
	arr[min]=arr[ploc];
	arr[ploc]=tmp;
	//printf("Lavish\n");
	flag++;

	return ploc;
}



