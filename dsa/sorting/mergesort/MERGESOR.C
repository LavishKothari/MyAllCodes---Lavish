//MERGE SORT

#include<stdio.h>
#include<conio.h>

void mergesort(int*,int ,int);
void merge(int *,int ,int);

//int b[20];

int main()
{
	//clrscr();
	int arr[20];
	int i,j,n;
	clrscr();
	printf("ENTER THE NUMBER OF ELEMENTS OF ARRAY:");
	scanf("%d",&n);
	printf("enter the data of array:\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);

	mergesort(arr,0,n-1);

	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);

	getch();
	return 1;
}

void mergesort(int *arr,int i,int j)
{
	int mid;
	if(i>=j)
	return;
	else
	{
		mid=(i+j)/2;
		mergesort(arr,i,mid);
		mergesort(arr,mid+1,j);
		merge(arr,i,j);
	}
}

void merge(int *arr,int i,int j)
{
	int start=i;
	int mid,k,l=i,b[20];
	mid=(i+j)/2;

	k=mid+1;

	while(k<=j&&i<=mid)
	{

		if(arr[i]<arr[k])
			b[l++]=arr[i++];
		else
			b[l++] =arr[k++];
	}

	if(i>mid)
		while(k<=j)
			b[l++]=arr[k++];
	else if(k>j)
		while(i<=mid)
			b[l++]=arr[i++];

	for(l=start;l<=j;l++)
		arr[l]=b[l];
}
