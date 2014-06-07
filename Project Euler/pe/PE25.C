#include<stdio.h>
#include<conio.h>
#include<time.h>

int get_digits(long double);

void main()
{

	long double a,b,sum,i=0;
	int digits,counter=2;

	clrscr();
	a=1;
	b=1;
	sum=0;
	while(1)
	{
		counter++;
		sum=a+b;
		
		a=b;
		b=sum;

		digits=get_digits(sum);

		if(digits==1000)
			break;
		i++;
	}
	printf("Answer = %d",counter);
	printf("\nEXECUTION TIME = %f",clock()/(float)CLK_TCK);
	getch();
}

int get_digits(long double n)
{
	int flag=0;
	while(n>1)
	{
		flag++;
		n/=10;
	}
	return flag;
}

