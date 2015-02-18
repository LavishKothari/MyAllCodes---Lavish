#include<stdio.h>

int main()
{
	int t;
	float n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f",&n);
		printf("%d ",(int)(6*n+1));
	}
	return 0;
}
