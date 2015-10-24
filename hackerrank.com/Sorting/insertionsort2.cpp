#include<stdio.h>
#include<stdlib.h>
void printArray(int*arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
void insertionSort(int*arr,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(temp<arr[j])
			{
				arr[j+1]=arr[j];
				//printArray(arr,n);
			}
			else break;
		}
		arr[j+1]=temp;
		printArray(arr,n);
	}
}
int main()
{
	int n,i,*arr;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	insertionSort(arr,n);
	//printArray(arr,n);
	free(arr);
	return 0;
}
