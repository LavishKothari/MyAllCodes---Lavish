// Program that takes coordinates of the centre point and a point on a circle as input and prints radius and area of a circle.
#include<stdio.h>
#include<math.h>
struct Point 
{
	double x,y;
};
double distance(const struct Point a,const struct Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	struct Point c,p;
	printf("Enter the x and y coordinates of center of circle : ");
	scanf("%lf%lf",&c.x,&c.y);
	printf("Enter the x and y coordinates of a point on circle : ");
	scanf("%lf%lf",&p.x,&p.y);
	double radius=distance(c,p);
	printf("Radius : %g\n",radius);
	printf("Area = %g\n",3.14*radius*radius);
	return 0;
} 
