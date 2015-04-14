#include<stdio.h>

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n>1)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
