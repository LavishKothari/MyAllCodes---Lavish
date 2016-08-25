#include<stdio.h>
typedef long long int ll;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
ll aabs(ll a,ll b)
{
	if(a>b)
		return a-b;
		return b-a;
}
int main()
{
	ll t,a,b,c,d,g,x,y;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		g=gcd(c,d);
		x=aabs(a,b)%g;
		y=(-aabs(a,b))%g+g;
		printf("%lld\n",x<y?x:y);
	}
	return 0;
}
