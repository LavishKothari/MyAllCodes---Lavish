#include<stdio.h>

typedef long long int ll;

ll fib(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else return fib(n-1)+fib(n-2);
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
