#include<stdio.h>
int isPrime(int n)
{
	int i;
	for(i=2;i*i<=n;++i)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
int power(int n,int counter)
{
	int product=1;
	while(counter--)
		product=product*n;
	return product;
}
int main()
{
	int t,n,cn,i,counter;
	long long int answer;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cn=n;
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		answer=n+1;
		if(isPrime(n))
			printf("%d\n",n+1);
		else
		{
			for(i=2;i*i<=cn;i++)
			{
				if(n%i==0)
				{
					answer+=i;
					if(n/i!=i)
						answer+=n/i;
				}
			}
			printf("%lld\n",answer);
		}
	}
	return 0;
}
