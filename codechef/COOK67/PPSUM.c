#include<stdio.h>
typedef long long int ll;
ll sum(ll a)
{
	return (a*(a+1))/2;
}
int main()
{
	ll t,d,n,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&d,&n);
		for(i=0;i<d;i++)
			n=sum(n);
		printf("%lld\n",n);
	}
	return 0;
}
