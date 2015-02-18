#include<stdio.h>

int main()
{
	int t,b,answer;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&b);
		answer=0;
		while(b>=2)
		{
			answer=answer+(b-2)/2;
			b-=2;
		}
		printf("%d\n",answer);
	}
	return 0;
}
