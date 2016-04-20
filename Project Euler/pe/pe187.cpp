#include<stdio.h>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100000001
//#define MAX 31
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
	int count=0;
	populateisPrime();
	for(int i=0;i<primes.size();i++)
	{
		int val=(MAX-1)/primes[i];
		int inc=upper_bound(primes.begin(),primes.end(),val)-upper_bound(primes.begin(),primes.end(),primes[i])+1;
		if(inc>0)
		{
			count+=inc;
			printf("count... %d\n",inc);
		}
	}
	printf("this is the final answer = %d\n",count);
	return 0;
}
