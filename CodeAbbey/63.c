#include<stdio.h>

int main()
{
	long long int t,i,n,counter,arr[10000];
	scanf("%lld",&t);
	while(t--)
	{
		counter=0;
		scanf("%lld",&n);
		while((n&1)==0)
		{
			arr[counter++]=2;
			n/=2;
		}
		for(i=3;i*i<=n;i+=2)
		{
			while(n%i==0)
			{
				arr[counter++]=i;
				n/=i;
			}
		}
		if(n>2)
			arr[counter++]=n;
		for(i=0;i<counter-1;i++)
			printf("%lld*",arr[i]);
		printf("%lld ",arr[counter-1]);
	}
	return 0;
}
