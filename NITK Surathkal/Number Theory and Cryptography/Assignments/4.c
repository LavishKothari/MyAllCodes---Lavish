/*
	Name - Lavish Kothari
		Computer Science and Engineering - Information Security
		NITK
		
	Question : 
	find out Euler's phi function for a power of a prime.
	Also give the list of all these numbers.
*/
#include<stdio.h>
long long int prime;
int isPowerOfPrime(long long int n) // this function returns 0 if n is not power of prime
									// otherwise it returns the power of that prime
{
	int i,counter=0,power=0;
	for(i=2;n!=1;i++)
	{
		if(n%i==0)
		{
			counter++;
			if(counter>=2)
				return 0;
			while(n%i==0)
			{
				prime=i;
				power++;
				n/=i;
			}
		}
	}
	return power;
}
long long int calPower(long long int a,long long int b)
{
	long long int power=1,i;
	for(i=0;i<b;i++)
		power=power*a;
	return power;
}
int main()
{
	long long int n,power,i,x,y;
	printf("Enter a number : ");
	scanf("%lld",&x);
	printf("Enter the power : ");
	scanf("%lld",&y);
	n=calPower(x,y);
	power=isPowerOfPrime(n);
	if(power!=0)
	{
		printf("\nphi(%lld) = %lld\n",n,calPower(prime,power-1)*(prime-1));
		printf("printing all the numbers, n such that GCD(n,%lld) = 1\n",n);
		for(i=1;i<n;i++)
			if(i%prime!=0)
				printf("%lld  ",i);
		printf("\n\n");
	}
	else
		printf("\nThe number you entered is not a power of prime\nExiting...\n\n");
	return 0;
}
