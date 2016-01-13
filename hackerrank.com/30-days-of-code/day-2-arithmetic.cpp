#include<stdio.h>
#include<math.h>
int main()
{
	double p,x,y;
	scanf("%lf%lf%lf",&p,&x,&y);
	printf("The final price of the meal is $%g.\n",round(p*(100+x+y)/100.0));
	return 0;
}
