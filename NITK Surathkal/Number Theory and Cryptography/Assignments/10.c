/*
	Lab program number 10
	ques : Write a program to print all the circular primes before 1 million
	
	This program uses seive of Eratosthenes to do so.
	
	program by 
		Lavish Kothari
		NITK Surathkal
		Number Theory and Cryptography lab.
*/

#include<stdlib.h>
#include<stdio.h>
#define MAX 1000000
int *primes;
void populatePrimeArray()
{
	int i,j;
	primes=(int*)malloc(sizeof(int)*(MAX+1));
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
long countDigits(long i) //counts the number of digits in the number i
{
	int counter=0;
	while(i)
	{
		counter++;
		i/=10;
	}
	return counter;
}
int power(int a,int b)
{
	int pro=1,i;
	for(i=0;i<b;i++)
		pro*=a;
	return pro;
}
int findCircular(int n,int x)
{
	int a,b;
	a=n%power(10,x);
	b=n/power(10,x);
	return a*power(10,countDigits(b))+b;
}
int isCircularPrime(int i)
{
	int flag,j,n,digits;
	if(primes[i])
	{
		flag=0;
		digits=countDigits(i);
		for(j=1;j<digits;j++)
		{
			n=findCircular(i,j);
			if(!primes[n])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			return 1;
		else return 0;
	}
	return 0;
}
int main()
{
	int i,counter;
	populatePrimeArray();
	counter=0;
	for(i=2;i<=MAX;i++)
	{
		if(isCircularPrime(i))
		{
			counter++;
			printf("%d\n",i);
		}
	}
	printf("Number of circular Primes before %d = %d\n",MAX,counter);
	return 0;
}

