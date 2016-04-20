#include<stdio.h>
typedef long long int ll;
ll max(ll a,ll b,ll c)
{
	return a>b?(a>c?a:c):(b>c?b:c);
}
ll min(ll a,ll b,ll c)
{
	return a<b?(a<c?a:c):(b<c?b:c);
}
ll middle(ll a,ll b,ll c)
{
	ll mi=min(a,b,c);
	ll ma=max(a,b,c);
	
	if(a==mi)
	{
		if(b==ma)
			return c;
		else return b;
	}
	if(b==mi)
	{
		if(a==ma)
			return c;
		else return a;
	}
	if(c==mi)
	{
		if(b==ma)
			return a;
		else return b;
	}
}
ll findAnswer(ll red,ll green,ll blue,ll k)
{
	ll answer,a,b,c;
	
	a=min(red,green,blue);
	b=middle(red,green,blue);
	c=max(red,green,blue);
	
	if(k<=a)
		return (k-1)*3+1;
	
	answer=0;
	if(a<k) answer+=a;
	if(b<k)
	 	answer+=b; 
	else
	{
		return answer+(k-1)*2+1;
	}
	return answer+k;
	
}
int main()
{
	ll t,r,g,b,k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&r,&g,&b,&k);
		printf("%lld\n",findAnswer(r,g,b,k));
	}
	return 0;
}
