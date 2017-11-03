#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power(ll a,ll b,ll m)
{
	if(a==0)
		return 0;
	if(b==0)
		return 1;
	ll temp=power(a,b/2,m);
	if(b&1)
		return (temp*temp*a)%m;
	return (temp*temp)%m;
}
ll rec(ll b,ll n,ll m) // gets (1 + b + b^2 + b^3 + ... + b^(n-1) )%m
{
	if(n==0)
		return 0;
	if(n==1)
		return 1%m;
	ll temp=((power(b,n/2,m)+1)*rec(b,n/2,m))%m;
	if(n&1)
		return (temp+power(b,n-1,m))%m;
	return temp;
}
ll getSumOfGP(ll a,ll r,ll n,ll m)
{
	return (a*rec(r,n,m))%m;
}
ll solve(ll n,ll m)
{
	if(m==1)
		return 0;
	ll answer=1;
	answer = (answer + (n-1)/m+1)%m; // for 1
	for(ll i=2;i<min(n+1,m);i++)
		answer=(getSumOfGP(power(i,i,m),power(i,m,m),(n-i)/m+1,m))%m;
	return answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",solve(n,m));
	}
	return 0;
}
