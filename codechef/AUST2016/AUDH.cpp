#include<stdio.h>
#include<vector>
#include<bitset>
using namespace std;
#define MAX_SIZE 1000000
bitset<MAX_SIZE+1> isPrime;
vector<int>phi(MAX_SIZE+1);
void populatePrimes()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i*i<=MAX_SIZE;i++)
		if(isPrime[i])
			for(int j=i*i;j<=MAX_SIZE;j+=i)
				isPrime[j]=0;
}

void populatePhi()
{
	for(int i=0;i<=MAX_SIZE;i++)
		phi[i]=i;
	for(int i=2;i<=MAX_SIZE;i++)
		if(isPrime[i])
			for(int j=i;j<=MAX_SIZE;j+=i)
				phi[j]=phi[j]-phi[j]/i;
}
int  main()
{
	populatePrimes();
	populatePhi();
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d %d\n",phi[a],phi[b]);
		if(phi[b]>=phi[a])
			printf("Case %d: Swapnil lost it\n",i+1);
		else
			printf("Case %d: Shibli took it\n",i+1);
	}
	return 0;
}
