#include<stdio.h>
typedef long long int ll;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	ll q,p,phi;
	p=1009;
	q=3643;
	phi=(q-1)*(p-1);
	ll counter=0;
	for(ll e=2;e<phi;e++)
	{
		if(gcd(e,phi)==1)
		{
			//printf("e = %lld\n",e);
			counter++;
		}
	}
	printf("counter = %lld\n",counter);
	return 0;
}
