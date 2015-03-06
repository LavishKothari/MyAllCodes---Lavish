#include<stdio.h>
#include<math.h>
long long int fib(int n)
{
	double phi;
	phi=(1+sqrt(5))/2.0;
	return (long long int)((pow(phi,n)-pow(-phi,-n))/sqrt(5));
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
		printf("%d %lld\n",i,fib(i));
	/*
	while(t--)
	{
		
	}
	*/
	return 0;
}
