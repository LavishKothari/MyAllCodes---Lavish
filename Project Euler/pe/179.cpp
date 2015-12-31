#include<stdio.h>
#include<vector>
#define MAX 1000000

typedef long long int ll;
using namespace std;

bool *isPrime;
int *divisorCount;
vector<int>primes;

void populatePrimeArray()
{
	isPrime=new bool[MAX];	
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<MAX;i++)
		isPrime[i]=true;
	for(int i=2;i<MAX;i++)
		if(isPrime[i])
			for(ll j=(ll)i*i;j<MAX;j+=i)
				isPrime[j]=false;
	for(int i=0;i<MAX;i++)
		if(isPrime[i])
			primes.push_back(i);
}
int countDivisors(int n) // the most naive algorithm. // this is very slow.
{
	int count=2; // 1 and n are always the divisors.
	if(!(n&1) && n!=2)
		count++;
	for(int i=2;i<n/2;i++)
		if(n%i==0)
			count++;
	return count;
}
int countDivisors1(int n) // counting number of divisors using prime factorization // this is still slow.
{
	int pro=1;
	for(vector<int>::iterator it=primes.begin();it!=primes.end() && n;it++)
	{
		int count=1;
		int currentPrime=*it;
		while(n%currentPrime==0)
		{
			count++;
			n/=currentPrime;
		}
		pro=pro*count;
	}
	return pro;
}
int countDivisors2(int n) // counting number of divisors using prime factorization // and storing the prime factorization of previous numbers.
{
	int pro=1;
	for(vector<int>::iterator it=primes.begin();it!=primes.end() && n;it++)
	{
		int count=1;
		int currentPrime=*it;
		while(n%currentPrime==0)
		{
			count++;
			n/=currentPrime;
		}
		pro=pro*count;
	}
	return pro;
}
int main()
{
	
	divisorCount=new int[MAX];
	populatePrimeArray();
	printf("populating prime array finished\n");
	divisorCount[0]=divisorCount[1]=0;
	
	for(int i=2;i<MAX;i++)
	{
		if(i%10000==0)
			printf("%d\n",i);
		divisorCount[i]=countDivisors(i);
		//printf("i = %d  = %d\n",i,divisorCount[i]);
	}
	/*
	for(vector<int>::iterator it=primes.begin();it!=primes.end();it++)
		printf("%d ",*it);
	
	printf("\nthis is the answer = %d\n",primes.size());
	*/
	
	return 0;
}
