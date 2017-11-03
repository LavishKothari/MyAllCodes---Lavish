#include<bits/stdc++.h>
using namespace std;
void sol(int n)
{
	if(n&1)
	{
		for(int i=0;i<n-2;i++)
			if(i&1)
				printf("%d ",i);
			else printf("%d ",i+2);
		printf("%d %d",n,n-2);
	}
	else
	{
		for(int i=0;i<n;i+=2)
			printf("%d %d ",i+2,i+1);
	}
	printf("\n");
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sol(n);
	}
	return 0;
}
