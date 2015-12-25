#include<stdio.h>
long long int findAnswer(long long int n)
{
	long long int x;
	x=n/10;
	return ((x*(x+1))/2)*10;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",findAnswer(n));
	}
	return 0;
}
