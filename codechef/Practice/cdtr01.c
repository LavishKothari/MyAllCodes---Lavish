#include<stdio.h>

int main()
{	
	int t,n,temp,k,arr[100],i,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		scanf("%d",&k);
		sum=0;
		for(i=0;i<k;i++)
		{
			scanf("%d",&temp);
			sum+=arr[temp-1];
		}
		printf("%d\n",sum);
	}
	return 0;
}
