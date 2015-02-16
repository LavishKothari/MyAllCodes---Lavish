#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int n,m,k,nodes,x,y,a,b,c,d;
	long long int **arr,i,j;
	scanf("%lld%lld%lld",&n,&m,&k);
	nodes=m*n+2;
	arr=(long long int**)malloc(sizeof(long long int*)*nodes);

	for(i=0;i<nodes;i++)
		arr[i]=(long long int*)malloc(sizeof(long long int)*nodes);

	for(i=0;i<nodes;i++)
		for(j=0;j<nodes;j++)
			arr[i][j]=0;

	for(i=1;i<=(n-1)*m;i++)
		for(j=0;j<m;j++)
			arr[i][((i-1)/m+1)*m+j+1]=1;

	for(i=1;i<=m;i++)
		arr[0][i]=1;
	for(i=m*(n-1)+1;i<=m*n;i++)
		arr[i][nodes-1]=1;
    /*
    for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	*/
	while(k--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a==0)x=0;else x=(a-1)*m+b+1;
		if(c==0)y=0;else y=(c-1)*m+d+1;
		arr[x][y]++;
	}
	for(i=0;i<nodes;i++)
		for(j=0;j<nodes;j++)
			for(k=0;k<nodes;k++)
				arr[i][j]=arr[i][j]+arr[i][k]*arr[k][j];
	/*
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
    */
    printf("%lld\n",arr[0][nodes-1]);
	return 0;
}
