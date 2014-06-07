#include<stdio.h>
#include<conio.h>
#include<math.h>

int isprime(long);

int main()
{
	long i;
	for(i=(long)sqrt(600851475143);i>=2;i--)
	{
		if(isprime(i)&&(600851475143%i==0))
		{
			printf("%ld\n",i);
			break;
		}
	}
		
	system("pause");
}

int isprime(long num)
{
	long i;
	for(i=2;i<=(long)sqrt(num);i++)
		if(num%i==0)
			return 0;
	return 1;
}
