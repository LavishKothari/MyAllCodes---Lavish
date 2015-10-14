#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<vector>
using namespace std;
#define MAX 5000001
int *answerArray,*primes;
vector <int>finePrimes;
void populatePrimes()
{
	int i,j,x;
	primes=(int*)malloc(sizeof(int)*(MAX+1));
	for(i=0;i<=MAX;i++)
		primes[i]=1;
	primes[0]=primes[1]=0; // because 0 and 1 is not a prime
	for(i=2;i*i<=MAX;i++)
		if(primes[i]==1)
			for(j=i*i;j<=MAX;j+=i)
				primes[j]=0;
}
void populateFinePrimes()
{
	int i;
	for(i=2;i<=MAX;i++)
		if(primes[i] && (i%4)==1)
			finePrimes.push_back(i);
}
void populateAnswerArray()
{
	int i,j;
	answerArray=(int*)malloc(sizeof(int)*(MAX+1));
	for(i=0;i<=MAX;i++)
		answerArray[i]=0;
	for(i=0;i<finePrimes.size();i++)
	{
		for(j=finePrimes[i];j<=MAX;j+=finePrimes[i])
			answerArray[j]=1;
	}
}
int main()
{
	int t,n,i,j;
	populatePrimes();
	populateFinePrimes();
	populateAnswerArray();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(answerArray[n]==1)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

