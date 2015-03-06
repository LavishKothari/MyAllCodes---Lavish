#include<stdio.h>
#include<math.h>
int main()
{
	int t,p,r,n;
	double a,m;
	scanf("%d%d%d",&p,&r,&n);
	a=1+r/1200.0;
	m=(pow(a,n)*p*(a-1))/(pow(a,n)-1);
	if(m!=(int)m)
	{
		m=(int)m+1;
	}
	printf("%g",m);
	return 0;
}
