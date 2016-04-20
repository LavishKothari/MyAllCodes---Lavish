#include<stdio.h>
#define MOD 1000000007
typedef long long int ll;
ll power(ll a,ll b)
{
	ll t;
	if(a==0) return 0;
	if(b==0) return 1;
	if(b==1) return a;
	t=power(a,b/2);
	if(b&1) return ((t*t)%MOD*a)%MOD;
	return (t*t)%MOD;
}
int main()
{
	ll t,n,k,answer;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		answer=k;
		answer=(answer*power(k-1,n-1))%MOD;
		printf("%lld\n",answer);
	}
	return 0;
}
