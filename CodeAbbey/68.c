#include<stdio.h>

int main()
{
	int t,a,b,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&s,&a,&b);
		printf("%.9f ",((a*s)/(double)(a+b)));
	}
	return 0;
}

