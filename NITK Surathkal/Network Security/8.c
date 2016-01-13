// write a program to find factorial of a number recursively.
#include<stdio.h>

typedef long long int ll;

ll factorial(int n)
{
	if(n==1)
		return 1;
	return factorial(n-1)*n;
}
int main()
{
	int n;
	printf("Enter n : ");
	scanf("%d",&n);
	printf("the factorial of %d is %lld\n",n,factorial(n));
	return 0;
}
