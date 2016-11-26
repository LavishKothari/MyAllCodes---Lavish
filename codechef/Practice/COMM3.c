#include<stdio.h>
typedef long long int ll;
ll dist2(ll a,ll b,ll c,ll d)
{
	return (c-a)*(c-a)+(d-b)*(d-b);
}
int main()
{
	ll t,r,a,b,c,d,e,f;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld",&r,&a,&b,&c,&d,&e,&f);
		if((dist2(a,b,c,d)<=r*r && dist2(a,b,e,f)<=r*r) || (dist2(c,d,a,b)<=r*r && dist2(c,d,e,f)<=r*r) || (dist2(e,f,c,d)<=r*r && dist2(e,f,a,b)<=r*r))
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
