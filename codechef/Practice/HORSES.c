/*
try to get AC in first go
try to solve as fast as possible
https://www.codechef.com/problems/MARCHA1
https://www.codechef.com/problems/HORSES
*/
#include<stdio.h>
#include<stdlib.h>
int arr[5001],n;
int c(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,min,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		qsort(arr,n,sizeof(int),c);
		min=1000000000;
		for(i=1;i<n;i++)
		{
			if(min>arr[i]-arr[i-1])
				min=arr[i]-arr[i-1];
		}	
		printf("%d\n",min);
	}
	return 0;
}
