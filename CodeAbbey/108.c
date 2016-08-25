#include<stdio.h>

int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		printf("%d ",n*(k-1));
	}
	return 0;
}

