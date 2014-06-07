#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int is_prime(long);

int is_prime(long n)
{
	int i=2;
	for(i=2;i<=(long)sqrt((double)n);i++)
		if(n%i==0)
			return 0;
	return 1;
}

int main()
{
	long i,j,sum=0,temp_terms=0,terms=0,ans=0,temp,num=1000000,a,actual_sum=0;
	for(i=2;i<num && ans<num;i++)
	{
		if(is_prime(i))
		{
			sum=0;
			temp_terms=0;
			a=0;
			for(j=i;;j++)
			{
				
				temp=sum;
			
				if(is_prime(j))
				{
					a++; // a counts the sequence of primes...
					sum+=j;
					if(sum>=num)
						break;
					if(is_prime(sum))
					{
						actual_sum=sum;
						temp_terms=a;
					}
				}
			}
			if(temp_terms>terms)
			{
				terms=temp_terms;
				ans=actual_sum;
			}
		}
	}

	printf("%d\n",ans);
	printf("Execution time = %f\n",clock()/(float)CLK_TCK);
	system("pause");
}