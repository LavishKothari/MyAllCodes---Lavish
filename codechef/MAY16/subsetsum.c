#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
#define MAX 1000001
typedef long long int ll;

//ll *arr,n,**T,sum,s;
ll *arr,n,T[1001][2*MAX+1001],sum,s;

void dp1()
{
	ll i,j,jc;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=sum;j++)
		{
			jc=j;
			j+=MAX;
			T[i][j]=0;
			//printf("%lld %lld %lld %lld\n",i,j,j+arr[i-1],j-arr[i-1]);
			if(j-arr[i-1]>=0)
				T[i][j]=(T[i][j]+T[i-1][j-arr[i-1]])%MOD;
			if(j+arr[i-1]<=sum)
				T[i][j]=(T[i][j]+T[i-1][j+arr[i-1]])%MOD;			
			j=jc;
		}
	}
}
void printT()
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=sum;j++)
			printf("%lld ",T[i][j]);
		printf("\n");
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
		
		/*
		T=(ll**)malloc(sizeof(ll*)*(n+1));
		for(i=0;i<=n;i++)
			T[i]=(ll*)malloc(sizeof(ll)*(sum+1));
		*/
		for(i=0;i<=sum;i++)
			T[0][i]=0;
		T[0][s]=1;
		
		dp1();
		/*
		printf("this is the table : \n\n");
		printT();
		printf("\n");
		*/
		for(j=1;j<=sum;j++)
			printf("%lld ",T[n][j]);
		printf("\n");		
	}
	return 0;
}
