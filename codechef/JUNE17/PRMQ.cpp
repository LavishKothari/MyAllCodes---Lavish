#include<bits/stdc++.h>
using namespace std;
#define N 1000001
bitset<N>isPrime;
typedef long long int ll;
vector<int>primes;
vector<map<int,int> >vm;
void pp()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i*i<=N;i++)
		if(isPrime[i])
			for(int j=i*i;j<N;j+=i)
				isPrime[j]=0;
	for(int i=0;i<N;i++)
		if(isPrime[i])
			primes.push_back(i);
}
void pre(vector<int>&a)
{
	// for each number in the array maintaining a map of divisors and their count.
	int n=a.size();
	for(int i=0;i<n;i++)
	{
		int counter=1;
		int nextPrime=2;
		int number = a[i];
		while(number!=1)
		{
			if(isPrime[number])
			{
				vm[i][number]++;
				break;
			}
			while(number!=1 && number%nextPrime==0)
			{
				vm[i][nextPrime]++;
				number/=nextPrime;
			}
			nextPrime=primes[counter++];
		}
	}
	/*
	   for(int i=0;i<n;i++)
	   {
	   cout<<"___________________________________\n";
	   cout<<a[i]<<endl;
	   for(map<int,int>::iterator it=vm[i].begin();it!=vm[i].end();it++)
	   {
	   cout<<it->first<<" "<<it->second<<endl;	
	   }
	   }
	 */
}
void sol(vector<int>&a,int l,int r,int x,int y)
{
	l--;r--;
	ll result=0;
	for(int i=x;i<=y;i++)
	{
		if(isPrime[i])
		{
			for(int j=l;j<=r;j++)
			{
				result+=vm[j][i];
			}
		}
	}
	printf("%lld\n",result);
}
int main()
{
	pp();
	int n;
	scanf("%d",&n);
	vm = vector<map<int,int> >(n);
	vector<int>a(n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	pre(a);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int L,R,X,Y;
		scanf("%d%d%d%d",&L,&R,&X,&Y);
		sol(a,L,R,X,Y);
	}
	return 0;
}
