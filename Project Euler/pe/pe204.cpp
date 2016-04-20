#include<stdio.h>
#include<bitset>
#define MAX 1000000001
using namespace std;
typedef long long int ll;
bitset<MAX>isPrime;
bitset<MAX>required;

void populatePrimes()
{	
	isPrime.reset();
	isPrime.flip();
	for(ll i=2;i*i<MAX;i++)
	{	
		//if(i%1000==0)
		printf("hello a %lld\n",i);	
		if(isPrime[i])
			for(ll j=i*i;j<MAX;j+=i)
				isPrime[j]=0;		
	}
	printf("populating primes finished\n");
}

ll populatePrimes1()
{	
	required.reset();
	required.flip();
	for(ll i=101;i<MAX;i++)
	{
		if(i%10000==0)
			printf("**********hello a %lld\n",i);	
		
		if(isPrime[i])
			for(ll j=i;j<MAX;j+=i)
				required[j]=0;
	}
	ll count=0;
	for(ll i=1;i<MAX;i++)
		if(required[i])
			count++;
	return count;
}

int main()
{
	populatePrimes();
	printf("%lld\n",populatePrimes1());
}
