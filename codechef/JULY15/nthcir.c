#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define MAX 20000000
double *table;
int floatcmp(float a, float b) 
{
    return !(a < b) && !(b < a);
}
double findFourth(double a,double b,double c,double r)
{
	double x,y;
	
	x = (a*a*b*b*c + a*a*b*c*c - 2*sqrt(a*a*a*a*b*b*b*c*c*c - a*a*a*b*b*b*b*c*c*c - a*a*a*b*b*b*c*c*c*c) - a*b*b*c*c)/(a*a*b*b - 2*a*a*b*c + a*a*c*c + 2*a*b*b*c + 2*a*b*c*c + b*b*c*c);
	y = (a*a*b*b*c + a*a*b*c*c + 2*sqrt(a*a*a*a*b*b*b*c*c*c - a*a*a*b*b*b*b*c*c*c - a*a*a*b*b*b*c*c*c*c) - a*b*b*c*c)/(a*a*b*b - 2*a*a*b*c + a*a*c*c + 2*a*b*b*c + 2*a*b*c*c + b*b*c*c);
	if(floatcmp(r,x)==0)
		return x;
	else 
		return y;
}
void initializeTable(double r1,double r2,double r3,double r4)
{
	long long int i;
	table[1]=r1;
	table[2]=r2;
	table[3]=r3;
	table[4]=r4;
	//table[5]=findFourth(r1,r2,r4,r3);
	for(i=5;i<MAX;i++)
	{
		table[i]=findFourth(r1,r2,r4,r3);
		r3=r4;
		r4=table[i];
	}
}
int main()
{
	double sum=0.0,r1,r2,r3,r4,r5,cr3,cr4,r,rprev; 
	long long int t,n0,p,m,b,newn,i;
	
	table=(double*)malloc(sizeof(double)*MAX);
	scanf("%lld",&t);
	scanf("%lld%lld%lld%lld",&n0,&p,&m,&b);
	scanf("%lf%lf%lf%lf",&r1,&r2,&r3,&r4);
	
	initializeTable(r1,r2,r3,r4);
	for(i=1;i<20;i++)
		printf("%f\n",table[i]/table[i+1]);
	cr3=r3;
	cr4=r4;
	while(t--)
	{
		newn=(p*n0)%m+b;
		
		if(newn<MAX)
		{
			sum+=table[newn];
		}
		else
		{
			r=table[MAX-1];
			rprev=table[MAX-2];
			for(i=MAX;i<=newn;i++)
			{
				r5=findFourth(r1,r2,r,rprev);
				rprev=r;
				r=r5;
			}
			sum+=r5;					
		}
		r3=cr3;
		r4=cr4;
		n0=newn;
	}
	printf("%f\n",sum);
	return 0;
}
