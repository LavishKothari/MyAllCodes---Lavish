#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	double r,a,b,c,s2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		s2=a+b+c;
		r=a*b*c/sqrt(s2*(s2-2*a)*(s2-2*b)*(s2-2*c));
		r=((long long int)(r*100))/100.0;
		printf("%.2lf\n",r);
	}
	return 0;
}
