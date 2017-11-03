#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 10000010

bitset<N+1>isPrime;
vector<ll>primes,primeSum;
void populatePrime()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i*i<=N;i++)
		if(isPrime[i])
			for(int j=i*i;j<=N;j+=i)
				isPrime[j]=0;
	for(int i=0;i<N;i++)
		if(isPrime[i])
		{
			primes.push_back(i);
			if(primeSum.size()==0)
				primeSum.push_back(i);
			else primeSum.push_back(primeSum.back()+i);
		}
}

int main()
{
	populatePrime();
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int i = lower_bound(primes.begin(),primes.end(),n)-primes.begin();
		if(primes[i]==n)
			cout<<primeSum[i]<<endl;
		else cout<<primeSum[i-1]<<endl;
	}
	return 0;
}