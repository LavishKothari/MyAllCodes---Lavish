#include<stdio.h>

int main()
{
	int t,i;
	long long int n,sum,nc;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		sum=0;
		nc=n;
		for(i=0;n;n/=10,i++);
		n=nc;
		while(n)
		{
			sum+=(n%10)*i;
			n/=10;
			i--;
		}
		printf("%lld ",sum);
	}
	return 0;
}
