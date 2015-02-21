#include<stdio.h>

int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c*c>a*a+b*b)
			printf("O ");
		else if(c*c==a*a+b*b)
			printf("R ");
		else if(c*c<a*a+b*b)
			printf("A ");
	}
	return 0;
}
