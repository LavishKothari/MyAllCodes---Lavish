#include<stdio.h>
#define MAX 1001
void swap(int *arr,int a,int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
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
		
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
		
		quicksort(arr,start,q-1,n);
		quicksort(arr,q+1,end,n);
	}
}

int main()
{
	int i,n,arr[MAX];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	quicksort(arr,0,n-1,n);
	
	/*
	printf("Final sorted array is : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	*/
	return 0;
}
