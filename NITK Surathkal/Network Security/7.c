// write a program to sort n numbers.
#include<stdio.h>
#include<stdlib.h>
void sort(int*arr,int n) // insertion sort
{
	int i,val,j;
	for(i=1;i<n;i++)
	{
		val=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>val)
				arr[j+1]=arr[j];
			else break;
		}
		arr[j+1]=val;
	}
}
	
int main()
{
	int n,*arr,i;
	printf("Enter the value of n : \n");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,n);
	printf("the sorted array is : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	
	return 0;
}
