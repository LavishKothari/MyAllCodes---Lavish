#include<stdio.h>
#include<math.h>


int main()
{
	double d,a,b;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&d,&a,&b);
		a=tan(a*M_PI/180.0);
		b=tan(b*M_PI/180.0);
		//printf("%lf %lf %lf\n",d,a,b);
		printf("%g\n",round(d*a*b/(b-a)));
	}
	return 0;
}
