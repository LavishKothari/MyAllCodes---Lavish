#include<stdio.h>

int main()
{
	int a,b,n,t,sum,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		sum=((2*a+(c-1)*b)*c)/2;
		printf("%d ",sum);
	}
	return 0;
}
