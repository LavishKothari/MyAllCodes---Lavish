#include<stdio.h>
#include<set>
#include<bitset>
#include<vector>
#include<math.h>
using namespace std;
typedef long long int ll;
#define MAX 1000001
#define RANGE 10000000000
bitset<MAX> isPrime;
vector<int>primes;
void populate_primes()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(ll i=2;i*i<MAX;i++)
		if(isPrime[i])
			for(ll j=i*i;j<MAX;j+=i)
				isPrime[j]=0;
				
	for(ll i=2;i<MAX;i++)
		if(isPrime[i])
			primes.push_back(i);
}

ll findmax(const ll a,ll i)
{

	ll mod;
	if(i%2==0)
		mod=2;
	else 
		mod=(2*a*i)%(a*a);
	printf("i = %lld  %lld\n",i,mod);
	if(mod>RANGE)
		return 1;
	return 0;
}
int main()
{
	populate_primes();
	int start=lower_bound(primes.begin(),primes.end(),(int)sqrt(RANGE))-primes.begin();
	ll i;
	for(i=start;;i++)
		if(findmax(primes[i-1],i))
			break;
	printf("%lld\n",i);
	return 0;
}
