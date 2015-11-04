#include<stdio.h>
#include<stdlib.h>
struct Point 
{
	double x,y;
};

int isGreater(double x,double y)
{
	if(x-y>0.0)
		return 1;
	else if(x-y<0.0)
		return -1;
	else return 0;
}
int cmp(const void*a,const void*b)
{
	struct Point c=*(struct Point*)a;
	struct Point d=*(struct Point*)b;
	return isGreater(c.x,d.x);
}
double min(double a,double b)
{
	if(isGreater(a,b)==-1)
		return a;
	return b;
}

double max(double a,double b)
{
	if(isGreater(a,b)==1)
		return a;
	return b;
}
int main()
{
	double a,b,c,d,e,f,p,q,r,s,t,u;
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	p=a+c-e;
	q=b+d-f;
	r=a+e-c;
	s=b+f-d;
	t=c+e-a;
	u=d+f-b;
	//printf("%0.4lf %0.4lf\n%0.4lf %0.4lf\n%0.4lf %0.4lf\n",p,q,r,s,t,u);
	struct Point points[3];
	points[0].x=p;
	points[0].y=q;
	
	points[1].x=r;
	points[1].y=s;
	
	points[2].x=t;
	points[2].y=u;
	
	qsort(points,3,sizeof(struct Point),cmp);
	
	if(isGreater(points[0].x,points[1].x)==0)
	{
		double mi=min(points[0].y,points[1].y);
		double ma=max(points[0].y,points[1].y);
		printf("%0.4lf %0.4lf\n",points[0].x,mi);
		printf("%0.4lf %0.4lf\n",points[1].x,ma);
		printf("%0.4lf %0.4lf\n",points[2].x,points[2].y);
	}
	else if(isGreater(points[1].x,points[2].x)==0)
	{
		printf("%0.4lf %0.4lf\n",points[0].x,points[0].y);
		double mi=min(points[1].y,points[2].y);
		double ma=max(points[1].y,points[2].y);
		printf("%0.4lf %0.4lf\n",points[1].x,mi);
		printf("%0.4lf %0.4lf\n",points[2].x,ma);
	}
	else 
	{
		printf("%0.4lf %0.4lf\n",points[0].x,points[0].y);
		printf("%0.4lf %0.4lf\n",points[1].x,points[1].y);
		printf("%0.4lf %0.4lf\n",points[2].x,points[2].y);
	}
	return 0;
}
