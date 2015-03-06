
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,counter,temp,*arr;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		counter=0;
		for(j=i-1;j>=0;j--)
		{
			if(temp<arr[j])
			{
				counter++;
				arr[j+1]=arr[j];
			}
			else break;
		}
		printf("%d ",counter);
		arr[j+1]=temp;
	}
}
