/*
	evaluate y= x^1 + x^2 + x^3 + x^4 + x^5 + ... + x^n  recursively
*/
#include<stdio.h>
double evaluate(double x,int n)
{
	if(n<=0) return 1;
	else return 1+x*evaluate(x,n-1);
}

int main()
{
	double x;
	int n;
	printf("Enter the value of x and n : ");
	scanf("%lf%d",&x,&n);
	printf("the answer is : %g\n",evaluate(x,n)-1);
	return 0;
}
