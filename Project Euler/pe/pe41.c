#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int count_digits(long);
int digit_sum(long);
int is_prime(long);
int contains_repeated(long );
int is_pandigital(long);

int main()
{
	long i,j;
	int digits;
	i=987654321;

	while(1)
	{
		digits=count_digits(i);
		if(digit_sum(i)%3==0)
		{
			i=i%(long)pow(10.0,digits-1);
			continue;
		}

		for(j=i;j>pow(10.0,digits-1);j--)
		{
			if(is_pandigital(j)&&is_prime(j))
			{
				
				printf("Answer = %ld",j);
				printf("\nEXECUTION TIME = %f\n",clock()/(float)CLK_TCK);
				system("pause");
				return;
			}
		}
	}
}

int count_digits(long num)
{
	int counter=0;
	while(num)
	{
		counter++;
		num/=10;
	}
	return counter;
}

int digit_sum(long num)
{
	int sum=0;
	while(num)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}


int is_prime(long num)
{
	long i;
	for(i=2;i<=(long)sqrt((double)num);i++)
		if(num%i==0)
			return 0;
	return 1;
}


int is_pandigital(long num)
{
	long c_num;
	int digit,max_digit=0;
	if(contains_repeated(num))
		return 0;
	
	
	digit=count_digits(num);
	c_num=num;
	while(c_num)
	{
		if(c_num%10>max_digit)
			max_digit=c_num%10;
		c_num/=10;
	}

	if(max_digit!=digit)
		return 0;

	return 1;
}


int contains_repeated(long num)
{
	long c_num;
	c_num=num;
	while(c_num)
	{
		if(c_num%10==0)
			return 1;
		c_num/=10;
	}
	c_num=num;
	while(num)
	{
		while(c_num)
		{
			if(num%10==(c_num/10)%10)
				return 1;
			c_num/=10;
		}
		num/=10;
		c_num=num;
	}
	return 0;
}	