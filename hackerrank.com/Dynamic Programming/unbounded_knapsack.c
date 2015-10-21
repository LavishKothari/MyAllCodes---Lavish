#include<stdlib.h>
#include<stdio.h>
int **table; // size = (k+1)*(n+1)
int max(int a,int b){ return a>b?a:b; }
int populateTable(int *arr,int n,int k)
{
	int i,j;
	for(i=0;i<=n;i++)
		table[0][i]=0;
	for(i=1;i<=k;i++)
	{
		table[i][0]=0;
		for(j=1;j<=n;j++)
		{
			if(i>=arr[j-1])
			{
				if(table[i-arr[j-1]][j]+arr[j-1] > i)
					table[i][j]=table[i][j-1];
				else table[i][j]=max(table[i-arr[j-1]][j]+arr[j-1],table[i][j-1]);
			}
			else
				table[i][j]=table[i][j-1];
			
		}
	}
	return table[k][n];
}
void printTable(int k,int n)
{
	int i,j;
	for(i=0;i<=k;i++)
	{
		for(j=0;j<=n;j++)
			printf("%d ",table[i][j]);
		printf("\n");
	}
}
int main()
{
	int t,n,k,i,*arr;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		arr=(int *)malloc(sizeof(int )*n);
		table=(int **)malloc(sizeof(int *)*(k+1));
		for(i=0;i<=k;i++)
			table[i]=(int *)malloc(sizeof(int )*(n+1));
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		printf("%d\n",populateTable(arr,n,k));
		//printTable(k,n);
		free(arr);
		for(i=0;i<=k;i++)
			free(table[i]);
		free(table);
	}
	return 0;
	// done :D
}
