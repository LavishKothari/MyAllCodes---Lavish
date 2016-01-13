#include<stdio.h>
#include<bitset>
#include<vector>
#include<math.h>
#include<algorithm>
#define N 10000000
using namespace std;
typedef long long int ll;
bitset<N+1>isPrime;
vector<int>primes;
void populatePrimes()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(ll i=2;(i<<1)<=N;i++)
		if(isPrime[i])
			for(int j=i<<1;j<=N;j+=i)
				isPrime[j]=0;
	for(int i=0;i<isPrime.size();i++)
		if(isPrime[i])
			primes.push_back(i);
}
ll findAnswer(ll n)
{
	vector<int>::iterator it;
	for(it=primes.begin();n!=1 && (ll)(*it)*(*it)<=n;it++)
		while(n%(*it)==0)
			n/=(*it);
	if(n==1)
		return *(it-1);
	else return n;
}
int main()
{
	int t;
	populatePrimes();
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",findAnswer(n));
	}
	return 0;
}
