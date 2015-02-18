#include<stdio.h>

int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a>b || a>c)
		{
			if(a<c || a<b)
			{
				printf("%d ",a);
			}
		}
		if(b>a || b>c)
		{
			if(b<a || b<c)
			{
				printf("%d ",b);
			}
		}
		if(c>a || c>b)
		{
			if(c<a || c<b)
				printf("%d ",c);
		}
	}
	return 0;
}

