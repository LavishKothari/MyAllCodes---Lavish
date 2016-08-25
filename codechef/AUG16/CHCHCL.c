#include<stdio.h>
typedef long long int ll;
int Awins(ll a,ll b)
{
	ll x=(a-1)*(b-1) + b-1;
	ll y=(a-1)*(b-1) + a-1;
	
	x=a-1+(b-1)*a;
	y=b-1+(a-1)*b;
	if(x&1 || y&1)
		return 1;
	return 0;
}
int main()
{
	int t;ll n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		if(Awins(n,m))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
