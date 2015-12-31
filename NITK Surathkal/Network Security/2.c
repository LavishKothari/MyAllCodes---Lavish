#include<stdio.h>

typedef long long int ll;

ll factorial(int n)
{
	int i;ll pro=1;
	for(i=1;i<=n;i++)
		pro=pro*i;
	return pro;
}
int main()
{
	int n;
	printf("Enter n : ");
	scanf("%d",&n);
	printf("the factorial of %d is %lld\n",n,factorial(n));
	return 0;
}
