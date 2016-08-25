#include<stdio.h>
#include<iostream>
#include<utility>
#include<bitset>
#include<vector>
using namespace std;
#define N 100000000
bitset<N+1>isPrime;
vector<int>phi(N+1);

void populatePrimes()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i*i<=N;i++)
		if(isPrime[i])
			for(int j=i*i;j<=N;j+=i)
				isPrime[j]=0;
	
}
void populatephi()
{
	for(int i=0;i<=N;i++)
		phi[i]=i;
	for(int i=1;i<=N;i++)
		if(isPrime[i])
			for(int j=i;j<=N;j+=i)
				phi[j]-=phi[j]/i;
	
}
int main()
{
	populatePrimes();
	populatephi();
	printf("Population finished\n");
	/*
	for(int i=2;i<=100;i++)
		if(isPrime[i])
			printf("%d\n",i);
	for(int i=2;i<=20;i++)
		printf("%d %d\n",i,phi[i]);
	*/
	int i=2;
	while(1)
	{
		double r=(double)phi[i]/(i-1);
		if(r<15499.0/94744.0)
		{
			printf("%d\n",i);
			break;
		}
		i++;
	}
	return 0;
}
