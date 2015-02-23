#include<stdio.h>

int main()
{
	int t,y;
	double s,r,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&s,&r,&p);
		y=0;
		while(s-r<0.0)
		{
			y++;
			s=s+s*(p/100);
			printf("%f\n",s);
			/*
			if((s-(int)s)!=0.0)
			{
				s=(int)s+1;

			}
			*/
		}
		printf("%d ",y);
	}
	return 0;
}
