// A057660
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define MAX 10000000
bool *primes;
int *phi;
vector<int>primeVector;
int*spf;
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
	spf=(int *)malloc(sizeof(int)*(MAX+1));
	for(int i=0;i<=MAX;i++) primes[i]=1;
	for(int i=0;i<=MAX;i++) spf[i]=0;
	primes[0]=primes[1]=false;

	primes[2]=true;
	for(int i=2*2;i<=MAX;i+=2)
	{
		primes[i]=false;
		spf[i]=2;
	}
	for(long long int i=3;i<=MAX;i+=2)
		if(primes[i])
		{
			spf[i]=i;
			for(long long int j=2*i;j<=MAX;j+=i)
			{
				if(spf[j]==0)
					spf[j]=i;
				primes[j]=false;
			}
		}
	for(int i=2;i<=MAX;i++)
		if(primes[i])
			primeVector.push_back(i);
}
long long int power(long long int a,long long int b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	long long int t;
	t=power(a,b/2);
	if(b&1)
		return t*t*a;
	else return t*t;
}
int main()
{
	int t;
	map<int,long long int>myanswers;
	scanf("%d",&t);
	populatePrimeArray();
	/*
	   for(vector<int>::iterator i=primeVector.begin();i!=primeVector.end();i++)
	   {
	   long long int currentPrime=*i;
	   myanswers[currentPrime]=(currentPrime*(currentPrime-1))+1;
	   for(int j=currentPrime*currentPrime,k=2;j<=MAX;j*=currentPrime,k++)
	   {
	   myanswers[j]=(power(currentPrime,(2*k+1))+1)/(currentPrime+1);
	   }
	   }
	 */
	//populatePhiArray();
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		bool found=(myanswers.find(n)==myanswers.end());
		if(!found)
		{
			printf("%lld\n",myanswers[n]);
			continue;
		}
		// this case handles for all primes.
		if(primes[n])
		{
			printf("%lld\n",(n*(n-1))+1);
			myanswers[n]=(n*(n-1))+1;
			continue;
		}
		/*
		   long long int answer=0;
		   long long int i;
		   for(i=1;i*i<n;i++)
		   if(n%i==0)
		   answer=answer+i*phi[i]+(n/i)*phi[n/i];
		   if(i*i==n)
		   answer+=i*phi[i];
		   printf("%lld\n",answer);
		 */
		long long int answer=1;
		/*
		   vector<int>::iterator i;
		   if(n&1)
		   i=primeVector.begin();
		   else
		   i=find(primeVector.begin(),primeVector.end(),spf[n]);
		 */
		for(int currentPrime=spf[n];n!=1;currentPrime++)
		{
			bool foundnext=(myanswers.find(n)==myanswers.end());
			if(!foundnext)
			{
				answer=answer*myanswers[n];
				break;
			}
			//int currentPrime=*i;
			//printf("this is a check : %d\n",currentPrime);
			if(n%currentPrime==0)
			{
				int counter=0;
				while(n%currentPrime==0)
				{
					counter++;
					n/=currentPrime;
				}
				answer=answer*((power(currentPrime,2*counter+1)+1)/(currentPrime+1));
			}
		}
		printf("%lld\n",answer);

	}
	free(primes);
	return 0;
}
