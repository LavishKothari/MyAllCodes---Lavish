#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,degree[100001]={0},i,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		degree[temp]++;
	}
	for(i=1;i<=n;i++)
		if(degree[i]==0)
			printf("%d ",i);
	printf("\n");
	return 0;
}
