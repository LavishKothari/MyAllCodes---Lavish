#include<stdio.h>
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a+b>=c && a+c>=b && b+c>=a)
			printf("1 ");
		else printf("0 ");
	}
	return 0;

}

