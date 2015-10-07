#include<math.h>
#include<stdlib.h>
#include<stdio.h>
struct Time
{	
	double degree;
	int h[721],m[721],length;
};
int doubleEqual(double a,double b)
{
	return fabs(a - b) < 1/120.0;
}
double findDegree(int h,int m)
{
	double temp;
	temp=m*6-h*30-0.5*m;
	if(temp>=0.0)
	{
		if(temp-180<=0.0)
			return temp;
		else
			return 360-temp;
	}
	else
	{
		if(temp+180>=0.0)
			return -temp;
		else
			return 360+temp;
	}
}
struct Time* findAnswer(double d)
{
	struct Time*a;
	int h,m;
	double temp;
	a=(struct Time*)malloc(sizeof(struct Time));
	(*a).length=0;
	for(h=0;h<12;h++)
	{
		for(m=0;m<60;m++)
		{
			temp=findDegree(h,m);
			if(doubleEqual(temp,d))
			{
				(*a).degree=d;
				(*a).h[(*a).length]=h;
				(*a).m[(*a).length]=m;
				(*a).length++;
			}
		}
	}
	return a;
}
int main()
{
	int t,i;
	double d;
	struct Time *a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&d);	
		a=findAnswer(d);
		for(i=0;i<(*a).length;i++)
		{
			if (a->h[i]>9 && a->m[i]>9)
				printf("%d:%d\n",a->h[i],a->m[i]);
			else if(a->h[i]<10 && a->m[i]>9)
				printf("0%d:%d\n",a->h[i],a->m[i]);
			else if(a->h[i]>9 && a->m[i]<10)
				printf("%d:0%d\n",a->h[i],a->m[i]);
			else if(a->h[i]<10 && a->m[i]<10)
				printf("0%d:0%d\n",a->h[i],a->m[i]);
		}
	}
	return 0;
}
