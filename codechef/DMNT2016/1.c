#include<stdio.h>
typedef long long int ll;
#define MOD 1589540031
int main()
{
	ll t,n,f[100001],i;
	scanf("%lld",&t);
	f[1]=1;
	for(i=2;i<=100000;i++)
		f[i]=(f[i-1]*i)%MOD;
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",f[n]);
	}
	return 0;
}
