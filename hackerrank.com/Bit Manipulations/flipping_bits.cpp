#include<stdio.h>
int flipithbit(unsigned int n,int i)
{
	return (((unsigned int)1)<<i)^n;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned int n;
		scanf("%u",&n);
		for(int i=0;i<32;i++)
			n=flipithbit(n,i);
		printf("%u\n",n);
	}
	return 0;
}
