#include<stdio.h>
int count1(unsigned char n)
{
	int counter=0;
	while(n)
	{
		if((n&1))
			counter++;
		n=n>>1;
	}
	return counter;
}
int main()
{
	int n,mask=1<<7;
	while(1)
	{
		scanf(" %d",&n);
		if(n=='.')
		{
			printf(".");
			break;
		}
		else if(count1(n)%2==0)
		{
			n=n&~mask;
			printf("%c",n);
		}
	}
}
