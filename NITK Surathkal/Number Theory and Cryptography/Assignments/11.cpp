#include<stdio.h>
#include<stdlib.h>
#define N 100
int *primes;
void populatePrimeArray()
{
	int i,j;
	primes=(int*)malloc(sizeof(int)*(N+1));
	primes[0]=primes[1]=0;
	for(i=2;i<=N;i++)
		primes[i]=1;
	for(i=2;i*i<=N;i++)
	{
		if(primes[i])
		{
			for(j=i*i;j<=N;j+=i)
				primes[j]=0;
		}
	}
}
int main()
{
	populatePrimeArray();
	int counter[N+1];
	for(int i=0;i<=N;i++)
		counter[i]=0;
	for(int i=2;i<=N;i++)
	{
		int ci=i;
		for(int j=2;ci!=1;j++)
			while(ci%j==0)
			{
				ci/=j;
				counter[j]++;
			}
	}
	int count=0;
	for(int i=0;i<=N;i++)
		if(counter[i]!=0)
		{
			count++;
			printf("%d %d\n",i,counter[i]);
		}
	printf("Total = %d\n",count);
	return 0;
}
