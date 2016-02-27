#include<stdio.h>
#include<bitset>
#include<set>
using namespace std;
#define MAX 1800010
typedef long long int ll;
bitset<MAX+1>primes;
void populatePrimes()
{
	primes.reset();
	primes.flip();
	primes[0]=primes[1]=0;
	for(ll i=2;i*i<MAX;i++)
			if(primes[i])
				for(ll j=i*i;j<MAX;j+=i)
					primes[j]=0;
}
int main()
{
	populatePrimes();
	/*
	for(int i=0;i<MAX;i++)
		if(primes[i])
			printf("%d\n",i);
	*/
	int n;
	scanf("%d",&n);
	int*arr=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	ll answer=0;
	set<int>my;
	for(ll i=1;i<(1<<n);i++)
	{
		ll ci=i;int counter=n-1;ll sum=0;
		while(ci)
		{
			if(ci&1)
			{
				sum+=arr[counter];
			}
			counter--;
			ci=(ci>>1);
		}
		if(primes[sum])
		{
			//printf("%lld\n",i);
			my.insert(sum);
		}
	}
	printf("%d\n",my.size());
	return 0;
}
