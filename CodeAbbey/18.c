#include<stdio.h>

int main()
{
	int t,i,iteration,n;
	double r,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&iteration);
		r=1;
		for(i=0;i<iteration;i++)
		{
			d=n/r;
			r=(r+d)/2;
		}
		printf("%.8f ",r);
	}
	return 0;
}
