#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int *arr=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qsort(arr,n,sizeof(int),cmp);
	int sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(k<sum+arr[i])
			break;
		sum+=arr[i];
	}
	printf("%d\n",i);
	return 0;
}
