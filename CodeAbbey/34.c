#include<stdio.h>
#include<math.h>
double a,b,c,d;
double f(double x)
{
	return (a*x+b*sqrt(x*x*x)-c*pow(2.7182818,-x/50.0)-d);
}
int main()
{
	int t;
	double sol1,sol2,sol3;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		sol1=0;
		sol2=100;
		sol3=(sol1+sol2)/2;
		while((int)(f(sol3)*100000000000.0)!=0)
		{
			if(f(sol3)<0.0)
			{
				sol1=sol3;
			}
			else
			{
				sol2=sol3;
			}
			sol3=(sol1+sol2)/2;
		}
		printf("%0.11f ",sol3);
	}
	return 0;
}
