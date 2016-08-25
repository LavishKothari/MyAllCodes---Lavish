#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
#define MAX 1001
typedef long long int ll;

ll *arr,n,prevT[MAX],currentT[MAX],sum,s;

void printT()
{
	int i,j;
	for(j=0;j<sum;j++)
		printf("%lld ",currentT[j]);
	printf("\n");
}

void dp1()
{
	ll i,j;
	
	for(i=0;i<=sum;i++)
		prevT[i]=0;
	prevT[s]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			currentT[j]=0;
			if(j-arr[i-1]>=1)
				currentT[j]=(currentT[j]+prevT[j-arr[i-1]])%MOD;
			if(j+arr[i-1]<=sum)
				currentT[j]=(currentT[j]+prevT[j+arr[i-1]])%MOD;			
		}
		//printT();
		for(j=0;j<=sum;j++)
			prevT[j]=currentT[j];
	}
}


int main()
{
	ll j,i,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&sum);
		scanf("%lld",&n);
		scanf("%lld",&s);
	
		arr=(ll*)malloc(sizeof(ll)*n);
		for(i=0;i<n;i++)
			scanf("%lld",arr+i);
		
		
		dp1();
		for(j=1;j<=sum;j++)
			printf("%lld ",currentT[j]);
		printf("\n");
		free(arr);
	}
	return 0;
}
