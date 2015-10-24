#include<stdlib.h>
#include<stdio.h>
int max(int a,int b){ return a>b?a:b; }
int populateTable1(int *arr,int n,int k)
{
	int i,j,answer;
	int **table; // size = (k+1)*(n+1)
	table=(int **)malloc(sizeof(int *)*(k+1));
	for(i=0;i<=k;i++)
		table[i]=(int *)malloc(sizeof(int )*(n+1));
		
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
	answer=table[k][n];
	for(i=0;i<=k;i++)
		free(table[i]);
	free(table);
	return answer;
}
int populateTable2(int *arr,int n,int k)
{
	int*Table,i,j,max,answer;
	Table=(int*)malloc(sizeof(int)*(k+1));
	Table[0]=0;
	for(i=1;i<=k;i++)
	{
		max=0;
		for(j=0;j<n;j++)
		{
			if(arr[j]<=i && max<Table[i-arr[j]]+arr[j])
				max=Table[i-arr[j]]+arr[j];
			else if(arr[j]<=i && max<Table[i-arr[j]])
				max=Table[i-arr[j]];
		}
		Table[i]=max;
	}
	answer=Table[k];
	//printTable(Table,n);
	return answer;
}
int main()
{
	int t,n,k,i,*arr;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		arr=(int *)malloc(sizeof(int )*n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		//printf("%d\n",populateTable1(arr,n,k));
		printf("%d\n",populateTable2(arr,n,k));
		free(arr);
		
	}
	return 0;
	// done :D
}
