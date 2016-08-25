#include<stdio.h>
struct line
{
	double m,c;
};
struct point
{
	int x,y;
};
struct line find1(int a,int b,int c,int d)
{
	struct line l;
	l.m=(d-b)/(double)(c-a);
	l.c=b-a*l.m;
	return l;
}
struct line find2(int a,int b,double slope)
{
	struct line l;
	l.m=slope;
	l.c=b-a*slope;
	return l;
}
struct point find3(struct line l1,struct line l2)
{
	struct point p;
	p.x=(l2.c-l1.c)/(l1.m-l2.m);
	p.y=l1.m*p.x+l1.c;
	return p;
}
int main()
{
	struct line l1,l2;struct point p;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		l1=find1(a,b,c,d);
		l2=find2(e,f,-1/l1.m);
		p=find3(l1,l2);
		// now check whether these line segements intersect or not.
		
	}
	return 0;
}
