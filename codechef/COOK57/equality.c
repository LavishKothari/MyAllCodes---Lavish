#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int sum;
	long long int t,i,n,*arr;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		sum=0;
		arr=(long long int*)malloc(sizeof(long long int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			sum+=arr[i];
		}
		sum/=(n-1);
		for(i=0;i<n;i++)
		{
			printf("%lld ",sum-arr[i]);
		}
		printf("\n");
	}
	return 0;
}