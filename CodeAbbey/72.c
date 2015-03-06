#include<stdio.h>
int A = 445, C = 700001, M = 2097152;
int main()
{
	char c[]={'b','c','d','f','g','h','j','k','l','m','n','p','r','s','t','v','w','x','z'};
	char v[]={'a','e','i','o','u'};
	int t,x,i,n;
	scanf("%d%d",&t,&x);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			x=(A*x+C)%M;
			if((i&1)!=0) // consonant
			{
				printf("%c",c[x%19]);
			}
			else
			{
				printf("%c",v[x%5]);
			}
		}
		printf(" ");
	}
	return 0;
}
