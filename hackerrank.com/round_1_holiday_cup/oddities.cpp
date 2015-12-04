#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int tem;
		scanf("%d",&tem);
		if(tem%2==0)
			printf("%d is even\n",tem);
		else printf("%d is odd\n",tem);
	}
	return 0;
}
