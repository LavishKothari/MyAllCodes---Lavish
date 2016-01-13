// write a iterative function to print fibonacci series.
#include<stdio.h>

typedef long long int ll;

ll fib(int n)
{
	int a,b,c,i;
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	a=0;b=1;
	for(i=0;i<n-1;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}
int main()
{
	int n,i;
	printf("Enter n : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		printf("%lld ",fib(i));
	return 0;
}
