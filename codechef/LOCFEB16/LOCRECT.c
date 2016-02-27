#include<stdio.h>
int main()
{
	int t,a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d %d\n",a*b+c*d-(a<c?a:c)*(b<d?b:d),a*b+c*d);
	}
	return 0;
}
