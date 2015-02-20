#include<stdio.h>

int main()
{
	int t,d1,d2,h1,h2,m1,m2,s1,s2,ts1,ts2,answer;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d%d",&d1,&h1,&m1,&s1,&d2,&h2,&m2,&s2);
		ts1=s1+m1*60+h1*60*60+d1*24*60*60;
		ts2=s2+m2*60+h2*60*60+d2*24*60*60;
		if(ts1>ts2)
			answer=ts1-ts2;
		else
			answer=ts2-ts1;
		printf("(%d",answer/(3600*24));
		answer=answer%(3600*24);
		printf(" %d",answer/3600);
		answer%=3600;
		printf(" %d",answer/60);
		answer%=60;
		printf(" %d) ",answer);
	}
	return 0;
}
