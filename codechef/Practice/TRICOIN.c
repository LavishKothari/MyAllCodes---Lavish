#include<stdio.h>
#include<math.h>
typedef long long int ll;
int main()
{
	int t;
	ll n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		x=(-1+sqrt(1+4*2*n))/2;
		printf("%lld\n",(ll)x);
	}
	return 0;
}
