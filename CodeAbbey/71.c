#include<stdio.h>
typedef long long int ll;
ll get(ll n)
{
	ll a,b,nc=2,c;
	a=0;b=1;
	c=a+b;
	while(c%n!=0)
	{
		nc++;
		a=b;
		b=c;
		c=(a+b)%n;
	}
	return nc;
}
int main()
{
	ll t,x;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&x);
		printf("%lld ",get(x));
	}
	return 0;
}
