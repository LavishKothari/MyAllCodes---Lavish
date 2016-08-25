#include<stdio.h>
typedef long long int ll;
int main()
{
	ll t,temp,i,answer,n,c[1000001];
	scanf("%lld",&t);
	while(t--)
	{
		answer=0;
		scanf("%lld",&n);
		for(i=0;i<1000001;i++)
			c[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&temp);
			c[temp]++;
		}
		for(i=0;i<1000001;i++)
			answer+=c[i]*(c[i]-1);
		printf("%lld\n",answer);
	}
	return 0;
}
