#include<stdio.h>
#include<stdlib.h>
int findContiguousSum(int *arr,int n)
{
	int sumSoFar=0,sumEndingHere=0, max;
	max=arr[0];
	for(int i=0;i<n;i++)
	{
		if(i>0 && arr[i]>max)
			max=arr[i];
		sumEndingHere+=arr[i];
		if(sumEndingHere<0)
			sumEndingHere=0;
		if(sumEndingHere>sumSoFar)
			sumSoFar=sumEndingHere;
	}
	if(max<=0)
		return max;
	else return sumSoFar;
}
int findNonContiguousSum(int *arr,int n)
{
	int sum=0;
	int max=arr[0];
	for(int i=0;i<n;i++)
	{
		if(i>0 && arr[i]>max)
			max=arr[i];
		
		if(arr[i]>0)
			sum+=arr[i];
	}		
	if(sum==0)
		return max;
	else return sum;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int *arr=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		printf("%d %d\n",findContiguousSum(arr,n),findNonContiguousSum(arr,n));
		free(arr);
	}
	return 0;
}
