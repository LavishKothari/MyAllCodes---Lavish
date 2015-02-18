#include<stdio.h>

int main()
{
	int t;
	unsigned int n,mask;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%u",&n);
		mask=2;
		while(mask)
		{
			n=(n&(~mask));
			mask=mask<<2;
		}
		printf("%u\n",n);
	}
	return 0;
}
