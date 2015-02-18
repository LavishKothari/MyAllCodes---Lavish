#include<stdio.h>

int main()
{
	int t,sum;
	long long int a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		a=a*b+c;
		sum=0;
		while(a)
		{
			sum+=a%10;
			a/=10;
		}
		printf("%d ",sum);
	}
	return 0;
}
