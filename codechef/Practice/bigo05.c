#include<stdio.h>
#define MOD 1000000007

int main()
{
	int t,n;
	long long int temp,pro;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		pro=1;
		while(n--)
		{
			scanf("%lld",&temp);
			pro=(pro*temp)%MOD;
		}
		printf("%lld\n",pro);
	}
	return 0;
}
