#include<stdio.h>

int main()
{
	int counter,t;long long int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		counter=0;
		while(n!=1)
		{
			if(n&1)
				n=n*3+1;
			else
				n=n/2;
			counter++;
		}
		printf("%d ",counter);
	}
	return 0;
}
