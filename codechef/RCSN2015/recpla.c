#include<stdlib.h>
#include<stdio.h>

long long int findSum(int i,int*arr,int n)
{
	long long int sum=0;
	int counter=n-1;
	while(i)
	{
		if(i&1)
			sum+=arr[counter];
		counter--;
		i=i>>1;
	}
	return sum;
}
int main()
{
	int *arr,t,i,n,c,range;
	long long int diff,min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		range=(1<<n)-1;
		min=1000000001;
		for(i=0;i<=range;i++)
		{
			diff=c-findSum(i,arr,n);
			//printf("%d %lld\n",i,diff);
			if(diff>=0 && diff<min)
				min=diff;
		}
		printf("%lld\n",min);
	}
	return 0;
}
