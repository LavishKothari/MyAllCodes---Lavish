#include<stdio.h>
#include<math.h>

double der(double x,double firstx,double yone,double secondx,double ytwo,double v1,double v2)
{
	double dfirst=sqrt(yone*yone+(x-firstx)*(x-firstx));
	double dsecond=sqrt(ytwo*ytwo+(x-secondx)*(x-secondx));
	double A=(x-firstx)*(x-secondx);
	return v2*(A/dsecond+dsecond)+v1*(A/dfirst+dfirst);
}
double f(double x,double firstx,double yone,double secondx,double ytwo,double v1,double v2)
{
	double dfirst=sqrt(yone*yone+(x-firstx)*(x-firstx));
	double dsecond=sqrt(ytwo*ytwo+(x-secondx)*(x-secondx));	
	return dsecond*v2*(x-firstx)-dfirst*v1*(secondx-x);
}
double dist(double a,double b,double c,double d)
{
	return sqrt((c-a)*(c-a) + (d-b)*(d-b));
}
int main()
{
	double a,b,c,d,v1,v2,cx,px,x,dfirst,dsecond,time;
	int test;
	scanf("%d",&test);
	while(test--)
	{	
		scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&v1,&v2);
		if(a==c)
			printf("%0.5lf\n",-b/v1+d/v2);
		else 
		{
			cx=(a+c)/2.0;
			do {
				px=cx;
				cx=px-f(px,a,b,c,d,v1,v2)/der(px,a,b,c,d,v1,v2);
			}while(fabs(cx-px)>0.001);

			x=cx;
			dfirst=sqrt(b*b+(x-a)*(x-a));
			dsecond=sqrt(d*d+(x-c)*(x-c));

			time=dfirst/v1+dsecond/v2;
			printf("%0.5lf\n",time);
		}
	}
	return 0;
}
