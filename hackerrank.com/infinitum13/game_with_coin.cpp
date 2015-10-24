#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==0 || b==0)
			printf("First\n");
		else
		{
			if((a+b-2)%2==0)
				printf("Second\n");
			else printf("First\n");
		}
	}
	return 0;
}
