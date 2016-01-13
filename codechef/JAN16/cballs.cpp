#include<stdio.h>
#include<bitset>
#include<vector>
using namespace std;
typedef long long int ll;
#define N 10000
vector<int>primes;
bitset<N+1>isPrime;
void populatePrimes()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(ll i=2;i*i<=N;i++)
	{
		if(isPrime[i])
		{
			for(ll j=i*i;j<=N;j+=i)
				isPrime[j]=0;
		}
	}
	for(int i=0;i<=N;i++)
		if(isPrime[i])
			primes.push_back(i);
}

ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
ll makeNonDecreasing(int*arr,int n)
{
	ll req=0;
	for(ll i=0;i<n-1;i++)
	{
		if(arr[i+1]<arr[i])
		{
			req+=arr[i]-arr[i+1];
			arr[i+1]+=arr[i]-arr[i+1];
		}
	}
	return req;
}
ll makeGCD(int*arr,int n,int x)
{
	ll req=0;
	for(int i=0;i<n;i++)
	{
		if((arr[i]%x) != 0)
		{
			req+=x-arr[i]%x;
		}
	}
	return req;
}
int main()
{
	int t;
	populatePrimes();
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int*arr=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		ll req=makeNonDecreasing(arr,n);
		int maxElement=arr[n-1];
		if(maxElement==1)
			maxElement++;
		ll mini=(ll)1<<62;
		for(vector<int>::iterator it=primes.begin();it!=primes.end();it++)
		{
			if((*it)>maxElement)
				break;
			ll tr=makeGCD(arr,n,*it);
			if(tr<mini)
				mini=tr;
		}
		printf("%lld\n",req+mini);
		delete arr;
	}
	return 0;
}
