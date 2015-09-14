#include<stdio.h>
#include<math.h>
int main()
{
	double answer,da,db;
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		da=a/100.0;
		db=b/100.0;
		answer=da*(1.0/(1-((1-da)*(1-db))));
		answer=answer*100;
		printf("%d ",(int)round(answer));
	}
	return 0;
}
