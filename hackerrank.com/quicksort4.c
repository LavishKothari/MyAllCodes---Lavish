#include<stdio.h>
#define MAX 1001
int swaps_quick=0;
int swaps_insertion=0;
void swap(int *arr,int a,int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
	swaps_quick++;
}
int partition(int*arr,int start,int end)
{	
	int i=start,pivot=arr[start],j; // considering first element as the pivot element.
	for(j=start+1;j<=end;j++)
	{	
		if(arr[j]<=pivot)
		{
			i++;
			swap(arr,j,i);
		}
	}
	swap(arr,i,start);
	
	return i;
}

int partition1(int*arr,int start,int end)
{	
	int i=start-1,pivot=arr[end],j; // considering last element as the pivot element.
	for(j=start;j<end;j++)
	{	
		if(arr[j]<=pivot)
		{
			i++;
			swap(arr,j,i);
		}
	}
	swap(arr,i+1,end);
	
	return i+1;
}



void quicksort(int*arr,int start,int end,int n)
{
	int q,i;
	if(start<end)
	{
		q=partition1(arr,start,end);
		/*
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
		*/
		quicksort(arr,start,q-1,n);
		quicksort(arr,q+1,end,n);
	}
}

void insertion_sort(int *arr,int n)
{
	int i,x,j;
	for(i=1;i<n;i++)
	{
		x=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>x)
			{
				swaps_insertion++;
				arr[j+1]=arr[j];
			}
			else break;
		}
		arr[j+1]=x;
	}
}

int main()
{
	int i,n,arr[MAX],arr1[MAX];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
		arr1[i]=arr[i];
	}
	quicksort(arr,0,n-1,n);
	insertion_sort(arr1,n);
	
	/*
	printf("Final sorted array is : ");
	for(i=0;i<n;i++)
		printf("%d ",arr1[i]); 
	printf("\n");
	*/
	
	printf("%d\n",swaps_insertion-swaps_quick);
	return 0;
}
