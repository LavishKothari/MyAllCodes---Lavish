#include<stdio.h>
#include<math.h>
long long int findc2(long long int n)
{
	int a;
	double b;
	for(a=1;a<n;a++)
	{
		if((n*n-2*a*n)%(2*n-2*a)==0)
		{
			return (long long int)(n-a-(n*n-2*a*n)/(2*n-2*a))*(n-a-(n*n-2*a*n)/(2*n-2*a));
		}
	}
	return 0;
}
int main()
{
	int n,t,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld ",findc2(n));
	}
	return 0;
}
