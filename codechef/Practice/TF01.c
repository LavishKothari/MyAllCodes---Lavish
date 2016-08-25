/**************************************************************/ // solution 1 Extra memory = O(sum*n)
/*
#include<stdio.h>
int arr[1001],T[1001][1001],n,k;
void dp()
{
	int i,j;
	for(j=0;j<=k;j++)
		T[0][k]=0;
	for(i=0;i<=n;i++)
		T[i][0]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=k;j++)
		{
			T[i][j]=T[i-1][j];
			if(j-arr[i-1]>=0)
				T[i][j]=(T[i][j] | T[i-1][j-arr[i-1]]);
		}
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",arr+i);
		dp();
		printf("%d\n",T[n][k]);	
	}
	return 0;
}
*/
/**************************************************************/ // solution 2 Extra memory = O(sum)
/*
#include<stdio.h>
int dp(int *arr,int n,int sum)
{
	int current[1001],prev[1001],i,j;
	for(i=0;i<=sum;i++)
		prev[i]=0;
	prev[0]=1;
	for(i=1;i<=n;i++)
	{
		current[0]=1;
		for(j=1;j<=sum;j++)
		{
			current[j]=prev[j];
			if(j-arr[i-1]>=0)
				current[j]=(current[j] | prev[j-arr[i-1]]);
		}
		for(j=0;j<=sum;j++)
			prev[j]=current[j];
	}
	return current[sum];
}
int main()
{
	int t,i,arr[1001],n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",arr+i);
		printf("%d\n",dp(arr,n,k));	
	}
	return 0;
}
*/
/****************************************************************/ // Solution 3
#include<stdio.h>
int dp(int *arr,int n,int sum)
{
	int T[2][1001],i,j,current;
	for(i=0;i<=sum;i++)
		T[0][i]=0;
	T[0][0]=1;
	current=1;
	for(i=1;i<=n;i++)
	{
		T[current][0]=1;
		for(j=1;j<=sum;j++)
		{
			T[current][j]=T[1^current][j];
			if(j-arr[i-1]>=0)
				T[current][j]=(T[current][j] | T[1^current][j-arr[i-1]]);
		}
		current=(current^1);
	}
	return T[1^current][sum];
}
int main()
{
	int t,i,arr[1001],n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",arr+i);
		printf("%d\n",dp(arr,n,k));	
	}
	return 0;
}
