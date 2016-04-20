#include<stdio.h>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000001
typedef long long int ll;
bitset<MAX>isPrime;
vector<int>primes;
void populateisPrime()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(ll i=2;i*i<MAX;i++)
	{
		printf("%lld\n",i);
		if(isPrime[i])
			for(ll j=i*i;j<MAX;j+=i)
				isPrime[j]=0;
	}
	for(ll i=2;i<MAX;i++)
		if(isPrime[i])
		{
			//printf("prime is %lld\n",i);
			primes.push_back(i);
		}
	printf("populate isPrime finished\n");
}

int main()
{
	ll count,n,p1,p2;
	populateisPrime();
	for(ll i=2;i<primes.size()-1;i++)
	{
		printf("%lld\n",i);
		p1=primes[i];
		p2=primes[i+1];
		n=1;
		count=0;
		while(1)
		{
			ll x=n*100+p1;
			if(x%p2==0)
			{
				count+=n;
				break;
			}
			n++;
		}
	}
	printf("%lld\n",count);
	return 0;
}
