#include<stdio.h>
#include<math.h>
int main()
{
	int t,a,b,c,e,d,f;
	double x,y,z,s,area;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		x=sqrt((a-e)*(a-e)+(b-f)*(b-f));
		y=sqrt((a-c)*(a-c)+(b-d)*(b-d));
		z=sqrt((c-e)*(c-e)+(d-f)*(d-f));
		s=(x+y+z)/2;
		area=sqrt(s*(s-x)*(s-y)*(s-z));
		printf("%f ",area);
	}
	return 0;
}

