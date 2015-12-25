#include<stdio.h>
bool findAnswer(int *arr,long long int *sum,int n)
{
	if(sum[n-1]-arr[0]==0)
		return true;
	if(n>=2 && sum[n-2]==0)
		return true;
	for(int i=1;i<n-1;i++)
	{
		if(sum[i-1]==sum[n-1]-sum[i])
			return true;
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int *arr=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		long long int *sum=new long long int[n];
		for(int i=0;i<n;i++)
			sum[i]=0;
		sum[0]=arr[0];
		for(int i=1;i<n;i++)
			sum[i]=sum[i-1]+arr[i];
		if(findAnswer(arr,sum,n))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
