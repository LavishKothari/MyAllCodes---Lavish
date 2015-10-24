#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int binarySearch(int *arr,int a,int b,int sval)
{
	int mid;
	while(a<=b)
	{
		mid=(a+b)/2;
		if(arr[mid]==sval)
			return mid;
		if(arr[mid]>sval)
			b=mid-1;
		else 
			a=mid+1;
	}
	return -1;
}
int main()
{
	int n,k,*arr;
	scanf("%d%d",&n,&k);
	arr=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qsort(arr,n,sizeof(int),cmp);
	int counter=0;
	for(int i=0;i<n-1;i++)
	{
		if(binarySearch(arr,i+1,n-1,arr[i]-k)!=-1 || binarySearch(arr,i+1,n-1,k+arr[i])!=-1)
		{
			counter++;
		}
	}
	printf("%d\n",counter);
	return 0;
}
