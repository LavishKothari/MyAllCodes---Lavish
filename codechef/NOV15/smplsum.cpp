// A057660
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 10000000
bool *primes;
int *phi;
void populatePhiArray()
{
	phi=(int*)malloc(sizeof(int)*(MAX+1));
	for(int i=0;i<=MAX;i++)
		phi[i]=i;
	for(int i=1;i<=MAX;i++)
		if(primes[i])
			for(int j=i;j<=MAX;j+=i)
				phi[j]-=phi[j]/i;
}
void populatePrimeArray()
{
	primes=(bool *)malloc(sizeof(bool)*(MAX+1));
	for(int i=0;i<=MAX;i++) primes[i]=1;
	primes[0]=primes[1]=false;
	for(int i=2;i*i<=MAX;i++)
		if(primes[i])
			for(int j=i*i;j<=MAX;j+=i)
				primes[j]=0;
}

int main()
{
	int t;
	scanf("%d",&t);
	populatePrimeArray();
	populatePhiArray();
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		// this case handles for all primes.
		if(primes[n])
		{
			printf("%lld\n",(n*(n-1))+1);
			continue;
		}
		long long int answer=0;
		long long int i;
		for(i=1;i*i<n;i++)
			if(n%i==0)
				answer=answer+i*phi[i]+(n/i)*phi[n/i];
		if(i*i==n)
			answer+=i*phi[i];
		printf("%lld\n",answer);
	}
	free(primes);
	free(phi);
	return 0;
}
