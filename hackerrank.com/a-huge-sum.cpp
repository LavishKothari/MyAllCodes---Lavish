#include<bits/stdc++.h>
using namespace std;
#define MAX 1000100
#define MOD 1000000007
typedef long long int ll;
//vector<int>primes;
vector<int>firstPrime(MAX,0);
vector< map<int,int> >number_of_divisors(MAX,map<int,int>());
bitset<MAX>isPrime;
	
void populatePrimes()
{
	isPrime.reset();
	isPrime.flip();

	isPrime[0]=isPrime[1]=0;
	for(int i=2;i*i<MAX;i++)
		if(isPrime[i])
			for(int j=i*i;j<MAX;j+=i)
			{
				if(firstPrime[j]==0)
					firstPrime[j]=i;
				isPrime[j]=0;	
			}
	
	for(int i=2;i<MAX;i++)
		if(isPrime[i])
		{
			firstPrime[i]=i;
			number_of_divisors[i][i]=1;
			//primes.push_back(i);
		}
	//cout<<"number of primes : "<<primes.size()<<endl;
}
void populateDivisors()
{
	number_of_divisors[0][0]=1;
	number_of_divisors[1][1]=0;

	for(int i=2;i<MAX;i++)
	{
		if(isPrime[i])
			continue;
		
		int n=i;
		int k=0;
		int p = firstPrime[i];
		int rem = n/p;
		
		
		number_of_divisors[i][p]=1;
		for(map<int,int>::iterator it=number_of_divisors[rem].begin();it!=number_of_divisors[rem].end();it++)
		{
			int key=it->first;
			int value=it->second;
			if(key!=p)
				number_of_divisors[i][key]=value;
			else number_of_divisors[i][p]+=value;
		}
		
	
	}
}


ll findAnswer(int n,int k)
{
	ll answer=1;
	for(int i=2;i<=n;i++)
	{
		ll pro=1;
		for(map<int,int>::iterator it=number_of_divisors[i].begin();it!=number_of_divisors[i].end();it++)
		{
			int element=it->second;
			pro=(pro*(element*k+1))%MOD;
		}
		answer=(answer+pro)%MOD;
	}
	return answer;
}

int main()
{
	clock_t begin = clock();
	populatePrimes();
	cout<<"population completed\n";
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<<"time taken = "<<time_spent<<endl;
	
	
	begin = clock();
	populateDivisors();
	cout<<"population completed\n";
	 end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<<"time taken = "<<time_spent<<endl;
	
	
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,n;
		scanf("%d%d",&n,&k);
		cout<<findAnswer(n,k)<<endl;
	}
	return 0;
}
