#include<stdio.h>
#define MOD 1000000007
#define MAX 100001
typedef long long int ll;
ll powerMOD(ll a,ll b)
{
	ll t;
	if(b==0) return 1;
	else if(b==1) return a;
	t=powerMOD(a,b/2);
	if(b&1)
		return ((t*t)%MOD*a)%MOD;
	return (t*t)%MOD;
}
ll inverseMOD(ll a)
{
	return powerMOD(a,MOD-2);
}
int main()
{
	ll t,i,arr[MAX],j,n,m,x,one,two,answer,prev,inter;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&x,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		answer=arr[x-1];
		prev=1;
		for(i=2;i<x+1;i++)
		{
			one=(i+m-2)%MOD;
			two=(m-1)%MOD;
			inter=((prev%MOD*one%MOD)%MOD*(ll)inverseMOD(one%MOD-two%MOD))%MOD;
			answer=(answer+(inter%MOD*arr[x-i])%MOD)%MOD;
			prev=inter%MOD;
		}
		printf("%lld\n",(answer)%MOD);
	}
	return 0;
}
