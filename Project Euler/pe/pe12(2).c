#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int no_of_divisors(long);
int isprime(long);
int main()
{
	int i,counter;
	long tri_no;
	
	for(i=1;;i++)
	{
		if(isprime(i+1))
			continue;
		tri_no=(i+1)*i/2;
		if(no_of_divisors(tri_no)>500)
		{
			printf("\nAnswer = %ld\n",tri_no,i);
			break;
		}
	}
	


	printf("\nEXECUTION TIME = %f\n",clock()/(float)CLK_TCK);
	system("pause");
}

int no_of_divisors(long num)
{
	long i;
	int counter=0;
	
	for(i=1;i<sqrt((double)num);i++)
		if(num%i==0)
			counter++;

	counter*=2;
	if(num%(long)sqrt((double)num)==0)
		counter++;
	return counter;
}

int isprime(long num)
{
	long i;
	for(i=2;i<=sqrt((double)num);i++)
		if(num%i==0)
			return 0;
	return 1;
}