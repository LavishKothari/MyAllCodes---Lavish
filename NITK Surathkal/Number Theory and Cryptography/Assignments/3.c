/*
	Name - Lavish Kothari
		Computer Science and Engineering - Information Security
		NITK
		
	Question # 3 :
	Write a program to find gcd of two numbers using Euclid's approach.
	Express 1 as the linear combination of two co-primes using the above program.
	Or in general express GCD(a,b) as the linear combination of a and b
*/
#include<stdio.h>
long long int x,y;
long long int GCD(long long int a,long long int b)
{
	long long int temp,q,remainder,quotient,px,py,ca,cb;
	py=x=0;
	ca=a;
	cb=b;
	px=y=1;
	while(b!=0)
	{
		quotient=a/b;
		remainder=a%b;
		
		a=b;
		b=remainder;
		if(remainder==0)
			break;
		
		temp=x;
		x=px-x*quotient;
		px=temp;
		
		temp=y;
		y=py-y*quotient;
		py=temp;
		printf("%lld = %lld * %lld + %lld * %lld\n",remainder,x,ca,y,cb);
		
	}
	return a;
}
int main()
{
	long long int a,b;
	printf("Enter the two numbers : ");
	scanf("%lld%lld",&a,&b);
	printf("\nGCD = %lld\n",GCD(a,b));
	printf("Expressing the gcd as the linear combination of a=%lld and b=%lld\n",a,b);
	printf("gcd = a*x + b*y\n");
	printf("then x = %lld   and   y = %lld\n\n",x,y);
	return 0;
}
