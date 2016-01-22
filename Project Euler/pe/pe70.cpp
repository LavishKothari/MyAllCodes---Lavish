#include<stdio.h>
#include<vector>
#include<bitset>
using namespace std;
#define MAX_SIZE 10000
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
bool isPermutation(int a,int b)
{
	int flag1[10]={0},flag2[10]={0};
	while(a)
	{
		flag1[a%10]++;
		a/=10;
	}
	while(b)
	{
		flag2[b%10]++;
		b/=10;
	}
	for(int i=0;i<10;i++)
		if(flag1[i]!=flag2[i])
			return false;
	return true;
}
int  main()
{
	populatePrimes();
	populatePhi();
	double ratio=(double)MAX_SIZE;int answer=0;
	for(int i=2;i<=MAX_SIZE;i++)
	{
		if(isPermutation(i,phi[i]))
		{
			printf("%d %d and ratio = %lf\n",i,phi[i],(double)i/phi[i]);
			if(ratio>(double)i/phi[i])
			{
				ratio=(double)i/phi[i];
				answer=i;
			}
		}
	}
	printf("The answer is : %d\n",answer);
	return 0;
}
