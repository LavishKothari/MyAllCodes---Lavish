#include<stdio.h>
typedef long long int ll;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		ll max=n;
		for(int i=1;i<n;i++)
		{
			ll temp;
			scanf("%lld",&temp);
			if(max<temp+i)
				max=temp+i;
		}
		for(int i=1;i<n;i++)
		{
			ll temp;
			scanf("%lld",&temp);
			if(max<temp+i)
				max=temp+i;
		}	
		printf("%lld\n",max);
	}
	return 0;
}

