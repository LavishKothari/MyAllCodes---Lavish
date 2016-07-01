#include<stdio.h>
typedef long long int ll;
int max(ll a,ll b)
{
	return a>b?a:b;
}
int min(ll a,ll b)
{
	return a<b?a:b;
}
int main()
{

	ll t,p,q,r,y,a,b,x ;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&p,&q,&r);
		y=(p*r)/(p+q);
		a=max(q*y,(r-y)*p);
		
		x=(q*r)/(p+q);
		b=max(p*x,(r-x)*q);
		
		printf("%d ",min(a,b));
	}	
	return 0;
}
