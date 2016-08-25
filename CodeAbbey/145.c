#include<stdio.h>
typedef long long int ll;
ll power(ll a,ll b,ll m)
{
	ll temp;
	if(b==0)
		return 1;
	temp=power(a,b/2,m);
	if(b&1)
		return (((temp*temp)%m)*a)%m;
	return (temp*temp)%m;
}
int main()
{
	ll t,a,b,m;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&m);
		printf("%lld ",power(a,b,m));
	}
	return 0;
}
