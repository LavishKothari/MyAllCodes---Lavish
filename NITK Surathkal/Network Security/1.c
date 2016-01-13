//Write a function to find GCD of two numbers and use it to find GCD of n numbers.

#include<stdio.h>

typedef long long int ll;

ll gcdRecursive(ll a,ll b)
{
	if(b==0)
		return a;
	return gcdRecursive(b,a%b);
}
ll gcdIterative(ll a,ll b)
{
	while(b)
	{
		ll temp=a;
		a=b;
		b=temp%b;
	}
	return a;
}
int main()
{
	int n,i;
	printf("Enter the count of numbers : ");
	scanf("%d",&n);
	printf("Enter %d numbers : \n",n);
	ll g,a,b;
	scanf("%lld %lld",&a,&b);
	g=gcdIterative(a,b);
	for(i=0;i<n-2;i++)
	{
		scanf("%lld",&a);
		g=gcdIterative(g,a);
	}
	printf("the gcd is : %lld\n",g);
	return 0;
}
