#include<stdlib.h>
#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int findMaxPossible(int size[],int value[],int n,int x)
{
	int **table,i,j;
	table=(int**)malloc(sizeof(int*)*(n+1));
	for(i=0;i<=n;i++)
		table[i]=(int*)malloc(sizeof(int)*(x+1));
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=x;j++)
		{
			if(i==0 || j==0)
				table[i][j]=0;
			else if(size[i-1]<=j)
				table[i][j]=max(value[i-1]+table[i-1][j-size[i-1]],table[i-1][j]);
			else
				table[i][j]=table[i-1][j];
		}
	}
	return table[n][x];
}
int main()
{
	int x,n,i;
	int *size,*value;
	scanf("%d%d",&x,&n);
	size=(int*)malloc(sizeof(int)*n);
	value=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d%d",&size[i],&value[i]);
	printf("%d",findMaxPossible(size,value,n,x));
	return 0;
}
