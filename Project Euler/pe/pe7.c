#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

long i_th_prime(int);

int main()
{
	int i=10001;
	printf("%ld",i_th_prime(i));
	printf("\nEXECUTION TIME = %f\n",(clock()/(float)CLK_TCK));
	system("pause");
}

long i_th_prime(int num)
{
	long i;
	int counter=0;
	for(i=2;;i++)
	{
		if(isprime(i))
			counter++;
		if(counter==num)
			break;
	}
	return i;
}

int isprime(long num)
{
	long i;
	for(i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
			return 0;
	}
	return 1;
}