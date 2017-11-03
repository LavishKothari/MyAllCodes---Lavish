#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAXN 10000010
vector<int>primes;
map<int,int>divisors;// storing the number of divisors 
void populatePrimes()
{
	bitset<MAXN>isPrime;
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i*i<MAXN;i++)
		if(isPrime[i])
			for(int j=i*i;j<MAXN;j+=i)
				isPrime[j]=0;
	for(int i=0;i<MAXN;i++)
		if(isPrime[i])
			primes.push_back(i);
}
int countDivisors(ll n)
{
	if(divisors[n]!=0)
		return divisors[n]; // if already computed, return the already computed value
	// otherwise computing it
	int cn=n;
	int i=0,answer=1;
	while(n!=1)
	{
		int power=0;
		while(n%primes[i]==0)
		{
			power++;
			n/=primes[i];
		}
		answer = answer*(power+1);
		i++;
	}
	divisors[cn]=answer;
	return answer;
}
ll findAnswer(int n)
{
	for(ll i=1;;i++)
	{
		int divisorCount=0;
		if(i&1)
			divisorCount = countDivisors(i)*countDivisors((i+1)/2);
		else divisorCount = countDivisors(i/2)*countDivisors(i+1);
		if(divisorCount>n)
			return (i*(i+1))/2;
	}
}
int main()
{
	populatePrimes();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll x=findAnswer(n);
		cout<<x<<endl;
	}
	return 0;
}
