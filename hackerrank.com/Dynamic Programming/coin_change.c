#include<stdio.h>
#include<stdlib.h>
long long int **table;
void populateTable(long long int*arr,long long int n,long long int min,long long int max,long long int sum)
{
	long long int i,j,answer;
	for(i=0;i<=n;i++)
		table[0][i]=1;
	for(i=1;i<=sum;i++)
	{
		table[i][0]=0;
		for(j=1;j<=n;j++)
		{
			answer=table[i][j-1];
			if(i>=arr[j-1])
				answer+=table[i-arr[j-1]][j];
			table[i][j]=answer;
		}
	}
}
void printTable(long long int a,long long int b)
{
	long long int i,j;
	for(i=0;i<=a;i++)
	{
		for(j=0;j<=b;j++)
			printf("%lld ",table[i][j]);
		printf("\n");
	}
	printf("\ntable printing done\n");
}
int main()
{
	long long int max,sum,rsum,n,*arr,min,i;
	scanf("%lld%lld",&rsum,&n);
	arr=(long long int*)malloc(sizeof(long long int)*n);
	max=0;
	min=2147483647;
	sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		if(max<arr[i])
			max=arr[i];
		if(min>arr[i])
			min=arr[i];
		sum+=arr[i];
	}
	table=(long long int**)malloc(sizeof(long long int*)*(sum+1));
	for(i=0;i<=sum;i++)
		table[i]=(long long int*)malloc(sizeof(long long int)*(n+1));
	populateTable(arr,n,min,max,sum);
	//printTable(sum,n);
	printf("%lld\n",table[rsum][n]);
	return 0;
}
