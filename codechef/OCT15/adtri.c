#include<stdio.h>
#include<math.h>
int isInt(double d)
{
	if(d-(int)d<0.000001)
		return 1;
	return 0;
}
int findAnswer(int n)
{
	int x;
	double costheta,temp;
	if(n==1)
		return 0;
	for(x=2;x<2*n;x+=2)
	{
		costheta=(double)x/(2.0*n);
		temp=n*sqrt(1-costheta*costheta);
		if(isInt(temp))
			return 1;
	}
	return 0;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(findAnswer(n)==1)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

