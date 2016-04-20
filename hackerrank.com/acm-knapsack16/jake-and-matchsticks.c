#include<stdio.h>
#define MOD 1000000007
int min2(int a,int b){return a<b?a:b;}
long long int dp(long long int*arr,long long int n,long long int sum)
{
	int table[sum+1],i,j;
	int currentsum=0;
	table[0]=1;
	for(i=1;i<=sum;i++)
		table[i]=0;
	
	for(i=0;i<n;i++)
	{
		currentsum+=arr[i];
		//printf("current sum = %d\n",currentsum);
		for(j=min2(sum,currentsum);j>=arr[i];j--)
		{
			table[j]+=table[j-arr[i]];
		}
	}
	/*
	for(i=0;i<=sum;i++)
		printf("%d ",table[i]);
	printf("\n");
	*/
	return table[sum];
}
long long int power(long long int a,long long b)
{
	long long int t;
	if(b==0) return 1;
	if(b==1) return a;
	t=power(a,b/2);
	if(b&1)
		return (((t*t)%MOD)*a)%MOD;
	return (t*t)%MOD;
}
int main()
{
	long long int n,k,x,arr[10001],number,i,j,sum;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",arr+i);
		sum+=arr[i];
	}
	number=0;
	for(x=1;k*x<=sum;x++)
		number+=dp(arr,n,k*x);
	printf("%lld\n",number);
	return 0;
}
