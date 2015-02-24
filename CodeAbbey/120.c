#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,temp,maxi,max,j,i,*arr;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=n-1;i>0;i--)
	{
		max=-2147483648;
		for(j=0;j<=i;j++)
		{
			if(arr[j]>max)
			{
				max=arr[j];
				maxi=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[maxi];
		arr[maxi]=temp;
		printf("%d ",maxi);
	}
	return 0;
}
