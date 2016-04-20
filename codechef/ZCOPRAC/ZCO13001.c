#include<stdlib.h>
#include<stdio.h>
typedef long long int ll;
int cmp(const void*a,const void*b)
{
	return *(ll*)b-*(ll*)a;
}
int main()
{
	ll n,sum=0,answer=0,i;
	ll arr[200001];
	scanf("%lld",&n);
	sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		sum+=arr[i];
	}
	qsort(arr,n,sizeof(ll),cmp);
	for(i=0;i<n;i++)
	{
		answer+=arr[i]*(n-i-1)-(sum-arr[i]);
		sum-=arr[i];
	}
	printf("%lld\n",answer);
	return 0;
}
