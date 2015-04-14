#include<stdio.h>

int main()
{
	int t,n,counter;
	scanf("%d",&t);
	while(t--)
	{
		counter=0;
		scanf("%d",&n);
		while(1)
		{
			if((n&1)==0)
			{
				counter++;
				n=n>>1;
			}
			else break;
		}
		printf("%d\n",counter);
	}
}
