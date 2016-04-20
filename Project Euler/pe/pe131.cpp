#include<stdio.h>
#include<bitset>
#define MAX 1000000
using namespace std;
typedef long long int ll;
bitset<MAX>isPrime;

void populatePrimes()
{	
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(ll i=2;i*i<MAX;i++)
	{	
		if(isPrime[i])
			for(ll j=i*i;j<MAX;j+=i)
				isPrime[j]=0;		
	}
	printf("populating primes finished\n");
}

int main()
{
	ll count=0,p;
	populatePrimes();
	ll x=1;
	while(1)
	{
		p=3*x*x+3*x+1;
		if(p>=MAX)
			break;
		if(isPrime[p])
			count++;
		x++;
	}
	printf("%lld\n",count);
}
