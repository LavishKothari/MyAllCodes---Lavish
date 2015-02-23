#include<stdio.h>
#include<math.h>
int main()
{
	int t,d,a,b,c;
	double r1,r2,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		d=b*b-4*a*c;
		if(d<0)
		{
			// equation has complex roots
			x=-b/(2*a);
			d=-d;
			y=sqrt(d)/(2*a);
			printf("%g+%gi ",x,y);
			printf("%g-%gi; ",x,y);
		}
		else
		{
			// equation has real roots
			r1=(-b+sqrt(d))/(2*a);
			r2=(-b-sqrt(d))/(2*a);
			printf("%g %g; ",r1>r2?r1:r2,r1<r2?r1:r2);
		}
	}
	return 0;
}
