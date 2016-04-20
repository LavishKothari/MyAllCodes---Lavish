#include<stdio.h>

int main()
{
	long long int t,n,rev;
	scanf("%lld",&t);
	while(t--)
	{
		rev=0;
		scanf("%lld",&n);
		while(n)
		{
			rev=rev*10+n%10;
			n/=10;
		}
		printf("%lld\n",rev);
	}
	return 0;
}
