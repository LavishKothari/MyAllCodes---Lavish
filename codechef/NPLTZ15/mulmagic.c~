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
	long long int sum,max,maxinarray;
	int t,arr[MAX+1],i,j,n;
	scanf("%d",&t);
	//populatePrimeArray();
	while(t--)
	{
		maxinarray=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{	
			scanf("%d",&arr[i]);
			if(arr[i]>maxinarray)
				maxinarray=arr[i];
		}
		max=0;
		for(i=2;i<=n;i++)
		{
			sum=0;
			//if(primes[i])
				for(j=i;j<=n;j+=i)
					sum=sum+arr[j];
			if(sum>max)
				max=sum;
		}
		/*
		if(maxinarray>max)
			max=maxinarray;
		*/
		printf("%lld\n",max);
	}
	return 0;
}
