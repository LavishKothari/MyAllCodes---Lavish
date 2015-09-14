#include<stdio.h>

int main()
{
	int t,i,n;
	long long int temp,sum1,sum2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum1=0;
		sum2=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&temp);
			if(i%2==0)
				sum1+=temp;
			else
				sum2+=temp;
		}
		printf("%lld\n",sum1>sum2?sum1:sum2);
	}
	return 0;
}
