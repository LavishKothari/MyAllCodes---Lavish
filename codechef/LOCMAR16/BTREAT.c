#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int t,n,answer,arr[100001],i,sum;
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			sum+=arr[i];	
		}
		if(sum%n==0)
		{
			answer=0;
			for(i=0;i<n;i++)
			{
				answer=answer+abs(arr[i]-sum/n);
			}
			printf("%lld\n",answer/2);
		}
		else 
		{
			printf("No Treat\n");
		}
	}
	return 0;
}
