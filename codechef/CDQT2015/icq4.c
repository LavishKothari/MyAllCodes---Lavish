#include<stdlib.h>
#include<stdio.h>
int*arr;
int main()
{
	int t,n,temp,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)	
			arr[i]=0;
		for(i=0;i<n-1;i++)
		{
			scanf("%d",&temp);
			arr[temp-1]=1;
		}
		for(i=0;i<n;i++)
		{
			if(arr[i]==0)
			{
				printf("%d\n",i+1);
				break;
			}
		}
		if(arr)
			free(arr);
	}
	return 0;
}
