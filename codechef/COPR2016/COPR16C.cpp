#include<stdio.h>
#define MOD 1000000007
typedef long long int ll;
ll power(ll a, ll b)
{
	if(b==0) return 1;
	if(b==1) return a;
	ll t=power(a,b/2);
	if(b&1) return ((t*t)%MOD*a)%MOD;
	else return (t*t)%MOD;
}

int main()
{
	int t;
	scanf("%d",&t);
	ll c=25*13;
	int len;
	while(t--)
	{
		scanf("%d",&len);
		printf("%lld\n",power(c,len));
	}
	return 0;
}
