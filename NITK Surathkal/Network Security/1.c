#include<stdio.h>

typedef long long int ll;

ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
ll gcd(ll a,ll b)
{	
	while
}
int main()
{
	int n,i;
	printf("Enter the count of numbers : ");
	scanf("%d",&n);
	printf("Enter %d numbers : \n",n);
	ll g,a,b;
	scanf("%lld %lld",&a,&b);
	g=gcd(a,b);
	for(i=0;i<n-2;i++)
	{
		scanf("%lld",&a);
		g=gcd(g,a);
	}
	printf("the gcd is : %lld\n",g);
	return 0;
}
