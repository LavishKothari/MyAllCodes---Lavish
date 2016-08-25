#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
#define MAX 100000
vector<int>antiprime;
vector <int>divisors(MAX,1);
void populate_divisors()
{
	for(int i=2;i<MAX;i++)
	{
		//if(i%100==0)
			//cout<<i<<endl;
		for(int j=i;j<MAX;j+=i)
			divisors[j]++;
	}
	int max=1;
	antiprime.push_back(1);
	for(int i=2;i<divisors.size();i++)
		if(divisors[i]>max)
		{
			max=divisors[i];
			antiprime.push_back(i);
		}
}

vector<int>primes;
bitset<MAX+1>isPrime;
void populate_primes()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i*i<=MAX;i++)
		if(isPrime[i])
			for(int j=i*i;j<=MAX;j+=i)
				isPrime[j]=0;
	for(int i=0;i<MAX;i++)
		if(isPrime[i])
			primes.push_back(i);
}


int main()
{
	populate_primes();
	/*
	cout<<"populate complete"<<endl;
	
	for(int i=0;i<primes.size();i++)
		cout<<primes[i]<<" "<<endl;
	*/
	
	return 0;
}
