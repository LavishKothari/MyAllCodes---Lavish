#include<stdlib.h>
#include<stdio.h>

int main()
{
	int j,t,max,min,temp,i,n,*arr;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		max=-1;
		min=1000000001;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(arr[i]-arr[j] > max)
					max=arr[i]-arr[j];
			}
		}
		printf("%d\n",max);
		free(arr);
	}
	return 0;
}
