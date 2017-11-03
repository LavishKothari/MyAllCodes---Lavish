#include<stdio.h>
#include<cmath>
using namespace std;
#define EPSILON 0.000001
bool isScalen(double x,double y,double z)
{
	if(abs(x-y)>EPSILON && abs(y-z)>EPSILON && abs(x-z)>EPSILON)
		return true;
	return false;
}
int findAngle(double x,double y,double z)
{
	double a,b,c;
	a=(x*x+y*y-z*z)/(2*x*y);
	b=(z*z+y*y-x*x)/(2*z*y);
	c=(x*x+z*z-y*y)/(2*x*z);
	if(abs(a-0.0)<EPSILON) return 1; // for right angles
	if(abs(b-0.0)<EPSILON) return 1;
	if(abs(c-0.0)<EPSILON) return 1;
	if(a>EPSILON && b>EPSILON && c>EPSILON) return 0; // for acute
	return 2; // for obtuse;
}
int main()
{
	int subtask,n;
	scanf("%d%d",&subtask,&n);
	double x,y,z;int a,b,c,d,e,f;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		x=sqrt((c-a)*(c-a)+(d-b)*(d-b));
		y=sqrt((e-c)*(e-c)+(f-d)*(f-d));
		z=sqrt((e-a)*(e-a)+(f-b)*(f-b));

		if(subtask==1)
		{
			if(isScalen(x,y,z))
				printf("Scalene triangle\n");
			else 
				printf("Isosceles triangle\n");
		}
		else
		{
			if(isScalen(x,y,z))
				printf("Scalene ");
			else 
				printf("Isosceles ");
			int find=findAngle(x,y,z);
			if(find==0) printf("acute triangle\n");
			else if(find==1) printf("right triangle\n");
			else if(find==2) printf("obtuse triangle\n");

		}
	}

	return 0;
}
