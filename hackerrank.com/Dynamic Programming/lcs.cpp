#include<stdio.h>
#include<stdlib.h>
void printTable(int**table,int n,int m)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			printf("%d ",table[i][j]);
		printf("\n");
	}	
}
int max(int a,int b){return a>b?a:b;}
void printLCS(int*x,int n,int *y,int m)
{
	int**table;
	table=(int**)malloc(sizeof(int*)*(n+1));
	for(int i=0;i<=n;i++)
		table[i]=(int*)malloc(sizeof(int)*(m+1));
	for(int i=0;i<=n;i++)
		table[i][0]=0;
	for(int j=0;j<=m;j++)
		table[0][j]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x[i-1]==y[j-1])
				table[i][j]=1+table[i-1][j-1];
			else table[i][j]=max(table[i-1][j],table[i][j-1]);
		}
	}
	//printTable(table,n,m);
	int i,j;
	i=n;j=m;
	int *lcs=(int*)malloc(sizeof(int)*table[i][j]);
	int counter=table[n][m]-1;
	while(1)
	{
		if(x[i-1]==y[j-1])
		{
			lcs[counter--]=x[i-1];
			i--;j--;
		}
		else 
		{
			if(table[i][j]==table[i-1][j])
				i--;
			else j--;
		}
		if(i==0 || j==0)
			break;
	}
	for(i=0;i<table[n][m];i++)
		printf("%d ",lcs[i]);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int*x=(int*)malloc(sizeof(int)*n);
	int*y=(int*)malloc(sizeof(int)*m);
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&y[i]);
	printLCS(x,n,y,m);	
	return 0;
}

