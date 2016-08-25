#include<stdio.h>
int arr[1001],T[1001][1001],n,k,flag[10],sum;
#define MOD 1000000009
void printT()
{
	int i,j;
	printf("this is the array\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=sum/k;j++)
			printf("%d ",T[i][j]);
		printf("\n");
	}
}
void dp()
{
	int i,j,tempsum,reqsum=sum/k;
	for(j=0;j<=reqsum;j++)
		T[0][j]=0;
	for(i=0;i<=n;i++)
		T[i][0]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=reqsum;j++)
		{
			T[i][j]=T[i-1][j];
			if(j-arr[i-1]>=0 && flag[i]==0)
				T[i][j]=(T[i][j] | T[i-1][j-arr[i-1]]);
		}
	tempsum=reqsum;
	for(i=n;i>0;i--)
		if(T[i-1][tempsum]==0)
		{
			flag[i]=1;
			//printf("%d ",arr[i-1]);
			tempsum-=arr[i-1];
		}
	/*
	for(i=0;i<=n;i++)
		printf("**%d ",flag[i]);
	printf("\n");
	printT();
	*/
}
int main()
{
	int t,i,counter;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10;i++)
			flag[i]=0;
		sum=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",arr+i);
			arr[i]%=k;
			sum+=arr[i];
		}
		if(sum%k!=0)
		{
			printf("no\n");
			continue;
		}
		correct=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]<=sum/k)
				correct++;
		}
		if(correct!=n)
		{
			printf("no\n");
			continue;			
		}
		counter=0;
		for(i=0;i<k;i++)
		{
			dp();
			if(T[n][sum/k]==1)
				counter++;
		}
		if(counter==k)
			printf("yes\n");
		else printf("no\n");	
	}
	return 0;
}
