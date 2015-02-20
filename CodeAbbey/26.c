#include<stdio.h>
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int t,a,b,g;
	long long int l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		g=gcd(a,b);
		l=(a*(long long int)b)/g;
		printf("(%d %lld) ",g,l);
	}
	return 0;
}
