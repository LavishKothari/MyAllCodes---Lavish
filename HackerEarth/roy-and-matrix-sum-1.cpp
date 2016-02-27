#include<stdio.h>
typedef long long int ll;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		ll sum=0;
		for(ll i=1;i<n;i++)
			sum+=(i*(i+1))/2;
		printf("%lld\n",sum*2);
	}
	return 0;
}
