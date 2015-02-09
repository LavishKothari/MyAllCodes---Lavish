#include<stdio.h>
#include<stdlib.h>
long long getSumBefore(long long int *arr,int n,int i)
{
	if(i!=0)
		return arr[i-1];
	else
		return 0;
}
long long int getSumAfter(long long int *arr,int n,int i)
{
	if(n!=0)
		return arr[n-1]-arr[i];
	else
		return 0;
}
int main()
{
	int t,i,*arr,n;
	long long int *sum,sumBefore,sumAfter;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		sum=(long long int*)malloc(sizeof(long long int)*n);
		for(i=0;i<n;++i)
		{
			scanf("%d",&arr[i]);
			if(i!=0)
				sum[i]=sum[i-1]+arr[i];
			else
				sum[i]=arr[i];
		}
		for(i=0;i<n;i++)
		{
			//printf("%d %lld        ",i,sum[i]);
			sumBefore=getSumBefore(sum,n,i);
			sumAfter=getSumAfter(sum,n,i);
			//printf("%lld %lld\n",sumBefore,sumAfter);
			if(sumBefore==sumAfter)
			{
				printf("%d\n",arr[i]);
				break;
			}
		}
		if(i==n)
			printf("NO EQUILIBRIUM\n");
		free(sum);
		free(arr);
	}
	return 0;
}
