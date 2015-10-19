#include<math.h>
#include<stdio.h>
#define MAX 100000
int primes[MAX+1];
void populatePrimeArray()
{
	int i,j;
	primes[0]=primes[1]=0;
	for(i=2;i<=MAX;i++)
		primes[i]=1;
	for(i=2;i*i<=MAX;i++)
	{
		if(primes[i])
		{
			for(j=i*i;j<=MAX;j+=i)
				primes[j]=0;
		}
	}
}
int main()
{
	int t,a,b,counter,i,arr[MAX];
	scanf("%d",&t);
	populatePrimeArray();
	arr[1]=0;arr[2]=1;
	for(i=3;i<MAX;i++)
	{
		if(primes[i])
			arr[i]=arr[i-1]+1;
		else
			arr[i]=arr[i-1];
	}
	while(t--)
	{
		counter=0;
		scanf("%d%d",&a,&b);
		printf("%d\n",arr[(int)sqrt(b)]-arr[(int)sqrt(a)]+primes[(int)sqrt(a)]);
	}
	return 0;
}
