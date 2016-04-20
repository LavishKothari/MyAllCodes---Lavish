#include<stdio.h>
typedef long long int ll;
#define MOD 1000000007
ll fact[2000001];
ll power(ll a,ll b)
{	
	ll temp;
	if(b==0) return 1;
	if(b==1) return a;
	temp=power(a,b/2);
	if(b&1)
		return ((temp*temp)%MOD*a)%MOD;
	return (temp*temp)%MOD;
}
ll inv(ll n)
{
	return power(n,MOD-2);
}
ll ncr(ll n,ll r)
{
	if(n==0 || r==0 || n==r)
		return 1;
	if(r==1)
		return n;
	return ((fact[n]*inv(fact[r]))%MOD*inv(fact[n-r]))%MOD;
}
int main()
{
	ll n,k;
	int t,i;
	fact[0]=1;
	for(i=1;i<2000001;i++)
		fact[i]=(fact[i-1]*i)%MOD;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		printf("%lld\n",ncr(n-1,k-1));
	}
	return 0;
}
