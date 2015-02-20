#include<stdio.h>

int main()
{
	int t,n,counter;
	unsigned int mask;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		counter=0;
		mask=1;
		while(mask)
		{
			if((n&mask)==mask)
				counter++;
			mask=mask<<1;
		}
		printf("%d ",counter);
	}
	return 0;
}
