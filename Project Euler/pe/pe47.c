#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int no_of_distinct_prime_factor(long);
int no_of_distinct_prime_factor(long);
int is_prime(long);

int main()
{
	long c=4,i,tmp,j;
	int flag;
	
	for(i=2;;i++)
	{
		flag=1;
		for(j=0;j<c;j++)
			if(!(c==no_of_distinct_prime_factor(i+j)))
			{
				flag=0;
				break;
			}
		
		if(flag)
		{
			printf("Answer = %d\n",i);
			break;
		}
	}
	
	printf("Execution time = %f\n",clock()/(float)CLK_TCK);
	system("pause");
}


int no_of_distinct_prime_factor(long n)
{
	int i,counter=0;
	long product=1;
	if(is_prime(n))
		return 1;
	for(i=2;i<=n/2;i++)
	{
		if(product*i > n)
			break;
		if(n%i==0 && is_prime(i))
		{
			product*=i;
			counter++;
		}
	}
	return counter;
}


int is_prime(long n)
{
	int i;
	for(i=2;i<=(long)sqrt((double)n);i++)
		if(n%i==0)
			return 0;
	return 1;
}