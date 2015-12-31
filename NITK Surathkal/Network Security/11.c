// binary search
#include<stdlib.h>
#include<stdio.h>
int binarySearch(int*arr,int a,int b,int sval)
{
	int mid;
	if(b<a)
		return -1;
	mid=(a+b)/2;
	if(arr[mid]==sval)
		return mid;
	if(arr[mid]>sval)
		return binarySearch(arr,a,mid-1,sval);
	else return binarySearch(arr,mid+1,b,sval);
}
int main()
{
	int i,n,*arr,sval,result;
	printf("Enter n : \n");
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter Element to be searched : ");
	scanf("%d",&sval);
	result=binarySearch(arr,0,n-1,sval);
	if(result==-1)
		printf("Element not found\n");
	else printf("Element found at position : %d\n",result);
	return 0;
}
