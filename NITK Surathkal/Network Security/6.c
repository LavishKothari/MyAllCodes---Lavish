#include<stdio.h>
double evaluate(double x,int n)
{
	int i;
	double pro=1,y=0;
	for(i=0;i<n;i++)
	{
		pro=pro*x;
		y+=pro;
	}
	return y;
}


int main()
{
	double x;
	int n;
	printf("Enter the value of x and n: ");
	scanf("%lf%d",&x,&n);
	printf("the answer is %g\n",evaluate(x,n));
	return 0;
}
