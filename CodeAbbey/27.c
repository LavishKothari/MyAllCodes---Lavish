#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*arr,i,j,flag,t,passes,swaps;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	passes=swaps=0;
	for(i=0;i<n;i++)
	{
	    flag=0;
	    passes++;
		for(j=0;j<n-i-1;j++)
		{
		    if(arr[j]>arr[j+1])
			{
			    swaps++;
			    flag=1;
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
		if(flag==0)
		    break;
	}
	printf("%d %d",passes,swaps);
	return 0;
}
