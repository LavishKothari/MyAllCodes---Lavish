#include<stdio.h>

int main()
{
	int t;
	long long int n,answer;
	scanf("%d",&t);
	t--;
	scanf("%lld",&n);
	answer=n*113;
	while(t--)
	{
		scanf("%lld",&n);
		answer=((answer+n)*113)%10000007;
	}
	printf("%lld ",answer);
	return 0;
}

