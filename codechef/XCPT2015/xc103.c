#include<stdio.h>

int main()
{
	int t,i,n;
	long long int answer[101];
	answer[1]=1;
	answer[2]=2;
	for(i=3;i<=100;i++)
		answer[i]=answer[i-1]*(i-1)+1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",answer[n]);
	}
	return 0;
}
