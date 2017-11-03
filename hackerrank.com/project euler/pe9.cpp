#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool findB(ll n,ll a, ll&b)
{
	ll N,D;
	N = n*(n-2*a);
	D = 2*(n-a);
	if(N%D || N==0)
		return false;
	b=N/D;
	return true;
}
ll findAnswer(ll n)
{
	ll m=-1;
	for(int i=1;i<n;i++)
	{
		ll a=i,b;
		if(findB(n,a,b))
			m=max(m,a*b*(n-a-b));
	}
	return m;
}

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",findAnswer(n));
	}
	return 0;
}