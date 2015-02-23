#include<stdio.h>
#include<stdlib.h>
int cfunc(const void*a,const void*b)
{
	return (*(int*)a-*(int*)b);
}
int findIndexOf(int val,int arr[],int len)
{
	int i;
	for(i=0;i<len;i++)
		if(arr[i]==val)
			return i+1;
	return -1;
}
int main()
{
	int n,*arr,i,*carr;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	carr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		carr[i]=arr[i];
	}
	qsort(arr,n,sizeof(int),cfunc);
	for(i=0;i<n;i++)
		printf("%d ",findIndexOf(arr[i],carr,n));
	return 0;
}
