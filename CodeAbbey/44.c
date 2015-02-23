#include<stdio.h>

int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%d ",(a%6+1+b%6+1));
	}
	return 0;
}
