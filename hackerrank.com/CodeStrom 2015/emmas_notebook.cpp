#include<stdio.h>
long long int sum(long long int n)
{
	return (n*(n+1))/2;
}
int main()
{
	int t;
	scanf("%d",&t);
	if(t%2==0)
		printf("%lld\n",sum(t/2)+sum(t/2+1)-1);
	else printf("%lld\n",sum(t/2+1)+sum(t/2+1)-1);
	return 0;
}
