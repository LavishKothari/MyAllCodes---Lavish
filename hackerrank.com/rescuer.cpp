#include<bits/stdc++.h>
using namespace std;

double der(double x,double x1,double y1,double x2,double y2,double v1,double v2)
{
	double d1=sqrt(y1*y1+(x-x1)*(x-x1));
	double d2=sqrt(y2*y2+(x-x2)*(x-x2));
	
	double A;
	A=(x-x1)*(x-x2);
	return v2*(A/d2+d2)+v1*(A/d1+d1);
}
double f(double x,double x1,double y1,double x2,double y2,double v1,double v2)
{
	double d1=sqrt(y1*y1+(x-x1)*(x-x1));
	double d2=sqrt(y2*y2+(x-x2)*(x-x2));
	
	return d2*v2*(x-x1)-d1*v1*(x2-x);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double a,b,c,d,v1,v2;
		scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&v1,&v2);
		
		if(a==c)
		{
			printf("%0.5lf\n",-b/v1+d/v2);
			continue;
		}
		double cx=a,px;
		do {
			px=cx;
			cx=px-f(px,a,b,c,d,v1,v2)/der(px,a,b,c,d,v1,v2);
		}while(abs(cx-px)>0.001);

		double x=cx;
		double d1=sqrt(b*b+(x-a)*(x-a));
		double d2=sqrt(d*d+(x-c)*(x-c));

		double answer=d1/v1+d2/v2;
		printf("%0.5lf\n",answer);

	}
	return 0;
}
