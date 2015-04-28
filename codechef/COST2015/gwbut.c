#include<stdio.h>
#define MOD 1000000007
long long int power(long long int a,long long int b)
{
	long long int temp;
	if(b==1)
		return a%MOD;
	temp=power(a,b/2);
	if(b%2==0)
		return (temp*temp)%MOD;
	else
		return (((temp*temp)%MOD)*a)%MOD;
}
int main()
{
	long long int n,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",power(7,n));
	}
	return 0;
}
