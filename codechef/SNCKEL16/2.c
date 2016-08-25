#include<stdio.h>
typedef long long int ll;
int findAnswer1(ll n , ll c)
{
	ll diff,A,X,B,y,P,I,p;
	ll sum=(n*(n+1))/2;
	p=2*c/n;
	if(n==1)
		return 1;
	
	if(c-sum<0)
		return 0;
	if(c-sum==0)
		return 1;
	
	
	if(2*c%n!=0)
		return 0;
		
	if(n%2==1)
	{
		if(c%n==0)
			return 1;
		return 0;
	}
	
	if(c%(n/2)!=0)
		return 0;
	
	I=c/n;
	
	if(p%2==0)
		I-=1;
	
	if(I-(p)>0)
		return 1;
	else return 0;
	
}

int main()
{
	ll t,n,c;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&c);
		if(findAnswer1(n,c))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
