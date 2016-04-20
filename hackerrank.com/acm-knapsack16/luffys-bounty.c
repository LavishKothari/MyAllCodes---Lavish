#include<stdio.h>
#include<stdlib.h>

int c(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n,k,i,arr[10001],sum=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
		sum+=arr[i];
	}
	qsort(arr,n,sizeof(int),c);
	for(i=0;i<k;i++)
	{
		if(arr[n-1-i]-arr[i]>arr[i])
			sum=sum-arr[i]+arr[n-1-i]-arr[i];
	}
	printf("%d\n",sum);
	return 0;
}
