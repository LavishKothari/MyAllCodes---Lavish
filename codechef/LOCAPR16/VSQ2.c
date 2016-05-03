#include<stdio.h>
#define MOD 1000000007
#define N 100001
typedef long long int ll;
ll fact[N],Answer[N];
ll power(ll a,ll b)
{
	ll temp;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	temp=power(a,b/2);
	if(b&1)
		return ((temp*temp)%MOD*a)%MOD;
	else return (temp*temp)%MOD;
}
ll inv(ll a)
{
	return power(a,MOD-2);
}
int main()
{
	int t,n,i;
	scanf("%d",&t);
	fact[0]=1;
	for(i=1;i<N;i++)
		fact[i]=(fact[i-1]*(ll)i)%MOD;
	Answer[1]=0;
	for(i=2;i<N;i++)
	{
		if(i&1)
			Answer[i]=(Answer[i-1]-inv(fact[i]))%MOD;
		else Answer[i]=(Answer[i-1]+inv(fact[i]))%MOD;
	}
	for(i=1;i<N;i++)
	{
		Answer[i]=(Answer[i]*fact[i])%MOD;
		if(Answer[i]<0)
			Answer[i]=Answer[i]+MOD;
	}
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",Answer[n]);
	}
	return 0;
}
