#include<stdio.h>

int main()
{
	int counter=0,t,n;
	scanf("%d",&t);
	while(t--)
	{
		counter=0;
		scanf("%d",&n);
		while(n)
		{
			if(n%10==4)
				counter++;
			n/=10;
		}
		printf("%d\n",counter);
	}
}
