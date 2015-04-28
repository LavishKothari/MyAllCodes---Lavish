#include<stdio.h>
#define MOD 1000000007

int main()
{
	long long int t,i,n,answer;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n<6)
			printf("FIGHT\n");
		else
		{
			answer=((((((((((n-5)*(n-4))%MOD)*(n-3))%MOD)*(n-2))%MOD)*(n-1))%MOD)*808333339)%MOD;
			printf("%lld\n",answer);
		}
	}
	return 0;
}
