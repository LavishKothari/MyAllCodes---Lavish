
//RECURSIVE QUICK SORT
//8 JANUARY 2013, 22:35:31
//BY LAVISH KOTHARI

#include<stdio.h>
#include<conio.h>

void quicksort(int*,int,int);

int main()
{
	int n,i,*arr;
	clrscr();

	printf("ENTER THE MAXIMUM NUMBER OF ELEMENTS");
	scanf("%d",&n);

	printf("ENTER THE DATA ELEMENTS THAT YOU WANT TO SORT");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	quicksort(arr,0,n-1);

	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);

	getch();
	return 1;
}

void quicksort(int*arr,int a,int b)
{
	int i=a+1,j=b,tmp;

	if(i>j)
		return;

	while(i<=j)
	{
		for(;arr[i]<arr[a]&&i<=b;i++);
		for(;arr[j]>arr[a]&&j>=a;j--);

		if(i<=j)
		{
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
		}
	}

	tmp=arr[a];
	arr[a]=arr[j];
	arr[j]=tmp;

	quicksort(arr,a,j-1);
	quicksort(arr,j+1,b);
}

