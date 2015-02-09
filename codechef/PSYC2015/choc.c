#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,i,j,k,n,u,temp,a,b,m;
	long long int *arr;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&u);
		arr=(long long int*)malloc(sizeof(long long int)*n);
		for(i=0;i<u;i++)
		{
			scanf("%d%d%d",&a,&b,&k);
			for(j=a;j<=b;j++)
				arr[j]+=k;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&temp);
			printf("%lld\n",arr[temp]);
		}
	}
	return 0;
}
