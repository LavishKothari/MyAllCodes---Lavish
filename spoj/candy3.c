#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int t,i,n,*arr,sum=0;
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
			sum%=n;
		}
		if(sum%n==0)
			printf("YES\n");
		else
			printf("NO\n");
		free(arr);
	}
	return 0;
}

