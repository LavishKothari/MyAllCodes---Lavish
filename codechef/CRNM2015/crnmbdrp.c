#include<stdio.h>
int main()
{
	int t,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		x-=100;
		if(x>=0)
		    printf("%f\n",(x/200.0));
		else
		    printf("0.000000\n");
	}
	return 0;
}
