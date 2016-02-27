#include<stdio.h>
#include<math.h>
int main()
{
	int t;double a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		printf("%lf %lf\n",(M_PI*a*a*b+2*M_PI*a*a*a)/3.0,M_PI*c*c*d);
	}
	return 0;
}
