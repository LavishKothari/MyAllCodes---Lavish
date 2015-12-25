#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int counter=0;
		while(n--)
		{
			int te;
			scanf("%d",&te);
			if(te<=0) counter++;
		}
		if(counter<k)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
