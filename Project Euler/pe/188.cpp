#include<stdio.h>
#define MOD 100000000
typedef long long int ll;
ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	ll t=power(a,b/2);
	if(b&1)
		return (((t*t)%MOD)*a)%MOD;
	return (t*t)%MOD;
}
ll he(ll a,ll b)
{
	if(b==1)
		return a%MOD;
	return power(a,he(a,b-1));
}
int main()
{
	printf("the answer is : %lld\n",he(1777,1855));
	return 0;
}
