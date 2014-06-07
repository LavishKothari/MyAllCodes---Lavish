#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

long count_digits(long);
long count_digits_upto(long);
int d(long);
int ith(long,long);

int main()
{
	long product=1;
	int i;
	for(i=0;i<7;i++)
		product*=d((long)pow(10.0,i));
	printf("%ld\n",product);
	printf("EXECUTION TIME = %f\n",clock()/(float)CLK_TCK);
	system("pause");
}

int d(long n)
{
	int ans;
	long i,tmp;
	i=getNumber(n);
	tmp=count_digits_upto(i-1);
	ans=ith(n-tmp,i);
	return ans;
}

int ith(long i,long n)
{
	int digits,j;
	digits=count_digits(n);
	for(j=0;j<digits-i;j++)
		n/=10;
	return n%10;
}
long count_digits_upto(long n)
{
	long counter=0,i;
	for(i=1;i<=n;i++)
		counter+=count_digits(i);
	return counter;
}

long getNumber(long n)
{
	long i,counter=0,product;
	for(i=1;i<=n;i++)
	{
		counter+=count_digits(i);
		if(counter>=n)
			break;	
	}
	return i;
}

long count_digits(long i)
{
	int counter=0;
	while(i)
	{
		counter++;
		i/=10;
	}
	return counter;
}