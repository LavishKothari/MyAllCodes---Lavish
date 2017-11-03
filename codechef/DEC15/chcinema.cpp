#include<stdio.h>
typedef long long int ll;

ll son(ll a)
{
	if(a&1)
		return a/2+1;
	return a/2;
}

ll findAnswer(ll n,ll m,ll z,ll l,ll r,ll b)
{
	if(z+l+r>=n*m || (b<=son(m)*n && b+z>=m*n))
		return n*m;
	ll answer=0;
	answer+=l+z;

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m,z,l,r,b;
		scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&z,&l,&r,&b);
		printf("%lld\n",findAnswer(n,m,z,l,r,b));
	}
	return 0;
}
