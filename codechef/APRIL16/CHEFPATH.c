#include<stdio.h>
typedef long long int ll;
int findAnswer(ll n,ll m)
{
	if(n==1 && m==1)
		return 0;
	if((n==1 && m==2) || (n==2 && m==1))
		return 1;
	if(n==1 || m==1)
		return 0;
	if(n%2==0 || m%2==0)
		return 1;
	return 0;
}
int main()
{
	int t;
	ll n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		if(findAnswer(n,m))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
