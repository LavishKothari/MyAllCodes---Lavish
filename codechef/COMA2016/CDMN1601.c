#include<stdio.h>
int c(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,n,sum,i;
	scanf("%d",&t);
	int arr[1002];
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<2*n;i++)
			scanf("%d",&arr[i]);
		qsort(arr,2*n,sizeof(int),c);
		for(i=0;i<n;i++)
			sum+=arr[2*n-1-i]-arr[i];
		printf("%d\n",sum);
	}
	return 0;
}
