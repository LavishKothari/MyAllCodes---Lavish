#include<stdio.h>
#define MOD 1000000007
typedef long long int ll;
ll fact[100001]; // precalculated factorials.
ll p[100001]; // precalculated powers of 2.
ll erse[100001]; // inverse array of factorials. // precalculated
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
ll powerIterative(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
			res=(res*a)%MOD;
		b=(b>>1);
		a=(a*a)%MOD;
	}
	return res;
}
ll ncr(ll n,ll r)
{
	if(n==0 || r==0 || n==r)
		return 1;
	if(r==1)
		return n;
	return ((fact[n]*erse[r])%MOD*erse[n-r])%MOD;
}
ll findAnswer(ll n,ll k,ll counter)
{
	ll sum=0,i,m;
	m=n<k?n:k;
	if(counter==0)
	{
		if(k>n)
			return p[2,n-1];
		if(k&1)
		{
			for(i=1;i<=m;i+=2)
				sum= (sum+ncr(n,i))%MOD;
		}
		else
		{
			for(i=0;i<=m;i+=2)
				sum= (sum+ncr(n,i))%MOD;		
		}
	}
	else
	{
		if(k>n)
			return p[2,n];
		for(i=0;i<=m;i++)
			sum= (sum+ncr(n,i))%MOD;
	}
	return sum;
}

void populate_inverse()
{
	ll i;
	erse[0]=1;
	erse[1]=1;
	for(i=2;i<100001;i++)
		erse[i]=powerIterative(fact[i],MOD-2);
}


int main()
{
	ll n,k,t,counter,temp,i;
	fact[0]=1;
	for(i=1;i<100001;i++)
		fact[i]=(fact[i-1]*i)%MOD;
	p[0]=1;
	for(i=1;i<100001;i++)
		p[i]=(p[i-1]*2)%MOD;
	populate_inverse();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		counter=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&temp);
			if(temp==0)
				counter++;
		}
		n-=counter;
		printf("%lld\n",findAnswer(n,k,counter));
	}
	return 0;
}
