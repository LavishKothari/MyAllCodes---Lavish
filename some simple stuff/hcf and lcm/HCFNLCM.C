#include<stdio.h>
#include<conio.h>

int main()
{
	long num1,num2,hcf,lcm,div,r;
	clrscr();
	printf("ENTER TWO NUMBERS : ");
	scanf("%ld%ld",&num1,&num2);

	hcf=num1>num2?num2:num1;
	div=num1>num2?num1:num2;
	r=div%hcf;

	while(r)
	{
		div=hcf;
		hcf=r;
		r=div%hcf;
	}

	lcm=(num1*num2)/hcf;
	printf("hcf = %ld\t\tlcm = %ld",hcf,lcm);
	getch();
	return 1;
}

