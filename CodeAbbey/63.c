#include<stdio.h>

int main()
{
	int t,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		while((n&1)==0)
		{
			printf("2*");
			n/=2;
		}
		for(i=3;i*i<=n;i+=2)
		{
			while(n%i==0)
			{
				printf("%d*",i);
				n/=i;
			}
		}
		if(n>2)
			printf("%d",n);
		printf(" ");
	}
	return 0;
}
