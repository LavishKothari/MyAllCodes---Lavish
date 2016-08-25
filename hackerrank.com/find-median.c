#include<stdio.h>
#define MAX 1000010
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

int quicksort(int*arr,int start,int end,int n)
{
	int q,i,x,y;
	if(start<end)
	{
		q=partition(arr,start,end);
		if(q==n/2)
			return arr[q];
		else if(q>n/2)
			return quicksort(arr,start,q-1,n);
		else 
			return quicksort(arr,q+1,end,n);
	}
	//if(start==end)
		return arr[start];
}

int main()
{
	int i,n,arr[MAX];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	printf("%d\n",quicksort(arr,0,n-1,n));
	
	return 0;
}
