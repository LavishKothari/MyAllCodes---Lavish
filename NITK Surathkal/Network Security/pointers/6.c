#include<stdio.h>
#define pi 3.14
int main()
{
	double radius;
	printf("Enter the radius : ");
	scanf("%lf",&radius);
	printf("Area = %g\nCircumference = %g\n",pi*radius*radius,2*pi*radius);
	return 0;
}
