#include<stdio.h>

int isPrime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}

int main()
{
	int t,n,i,arr[200000],counter;
	scanf("%d",&t);
	counter=1;
	i=2;
	while(counter!=200000)
	{
		if(isPrime(i))
		{
			arr[counter]=i;
			counter++;
		}
		i++;
	}
	while(t--)
	{
		scanf("%d",&n);
		printf("%d ",arr[n]);
	}
	return 0;
}
