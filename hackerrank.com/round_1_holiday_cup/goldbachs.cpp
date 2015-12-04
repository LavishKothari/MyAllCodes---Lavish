#include<stdio.h>
#include<vector>
#define MAX 100000
using namespace std;
vector<bool>primes(MAX);
void populateSeive()
{
	primes[0]=primes[1]=false;
	
	for(long long int i=2;i<MAX;i++)
		primes[i]=true;
	for(long long int i=2;i*i<=MAX;i++)
	{
		if(primes[i])
			for(long long int j=i*i;j<MAX;j+=i)
				primes[j]=false;
	}
}
int main()
{
	int t;
	populateSeive();
	/*
	for(int i=0;i<primes.size();i++)
		if(primes[i])
			printf("%d\n",i);
	*/
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int>a,b;
		for(int i=1;i<=n/2;i++)
		{
			if(primes[i] && primes[n-i])
			{
				a.push_back(i);
				b.push_back(n-i);
			}
		}
		printf("%d has %d representation(s)\n",n,a.size());
		for(int i=0;i<a.size();i++)
			printf("%d+%d\n",a[i],b[i]);
		printf("\n");
	}
	
	return 0;
}
