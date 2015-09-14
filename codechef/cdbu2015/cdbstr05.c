#include<stdio.h>
#include<stdlib.h>
int cmpf(const void*a,const void*b)
{
	return *(long long int*)b-*(long long int*)a;
}
int main()
{
	long long int answer,sum;
	long long int t,*arr,n,i,j;
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		scanf("%lld",&n);
		arr=(long long int*)malloc(sizeof(long long int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			sum+=arr[i];
		}
		qsort(arr,n,sizeof(long long int),cmpf);
		answer=0;
		for(i=0;i<n;i++)
		{
			answer=answer+(n-i-1)*arr[i]-(sum-arr[i]);
			sum-=arr[i];
		}
		printf("%lld\n",answer);
	}
	
	return 0;
}
