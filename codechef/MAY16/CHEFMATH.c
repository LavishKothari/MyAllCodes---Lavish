#include<stdio.h>
typedef long long int ll;
#define MAX 1000000000
ll fib[200],fiblen=0;
void populateFib()
{
	fib[0]=1;
	fib[1]=2;
	fiblen=2;
	while(1)
	{
		fib[fiblen]=fib[fiblen-1]+fib[fiblen-2];
		if(fib[fiblen]<=MAX)
			fiblen++;
		else 
			break;
	}
}
int main()
{
	int t;
	populateFib();
	printf("fiblen = %lld\n",fiblen);
	/*
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&k);
		
	}
	*/
	return 0;
}
