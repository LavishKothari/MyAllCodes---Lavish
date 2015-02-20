#include<stdio.h>

int main()
{
	int t,x1,y1,x2,y2;
	int a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		a=(y2-y1)/(float)(x2-x1);
		b=(x2*y1-y2*x1)/(x2-x1);
		printf("(%d %d) ",a,b);
	}
	return 0;
}
