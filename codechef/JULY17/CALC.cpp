#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll solve(ll n,ll b)
{
	if(n<=b)
		return 0;
	ll y1=n/(2*b);
	ll x1=n-(y1*b);
	ll x2=0,y2=0;
	if(n%(2*b)!=0)
	{
		y2=n/(2*b)+1;
		x2=n-(y2*b);
	}
	return max(x1*y1,x2*y2);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,b;
		scanf("%lld%lld",&n,&b);
		printf("%lld\n",solve(n,b));
	}
	return 0;
}
