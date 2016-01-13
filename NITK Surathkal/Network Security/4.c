// Write a program to find position of largest element in a given array.

#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;

int findPosOfMax(int *arr,int n)
{
	int i,pos=0,max=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			pos=i;
		}
	}
	return pos;
}
int main()
{
	int n,i,*arr;
	printf("Enter n : ");
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("the position of maximum element is : %d\n",findPosOfMax(arr,n));
	return 0;
}
