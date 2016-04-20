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

int main()
{
	populatePrimes();
}
