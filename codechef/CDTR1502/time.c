#include<stdio.h>
long long int fun(int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 2;
	return 2*fun(n-1);
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld",fun(n));
	return 0;
}
