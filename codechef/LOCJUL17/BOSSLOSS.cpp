#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll get(ll n)
{
	ll x=(ll)sqrt(n);
	while(x*x<n)
		x++;
	if(x*x==n)
		return x;
	return x-1;
}
ll solve(ll n,ll m)
{
	ll ta,answer,x;
	x=get(8*m+1);
	ta=(x-1)/2;
	if((ta*(ta+1))/2 >= m)
		answer=ta;
	else 
		answer=ta+1;
	if(answer<=n)
		return answer;
	return -1;
}
int main()
{
	int t;
	ll n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",solve(n,m));
	}
	return 0;
}
