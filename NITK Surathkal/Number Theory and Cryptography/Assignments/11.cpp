/*
	Find the powers of all the prime factors of 100! 
*/

#include<stdio.h>
#include<stdlib.h>
#define N 100
int main()
{
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
	printf("Number\tPower\n");
	for(int i=0;i<=N;i++)
		if(counter[i]!=0)
		{
			count++;
			printf("%d\t%d\n",i,counter[i]);
		}
	printf("\nTotal Primes = %d\n",count);
	return 0;
}
