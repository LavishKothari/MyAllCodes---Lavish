#include<stdio.h>
#include<stdlib.h>
int**x,**y,**arr;
int main()
{
	int t,prevx,prevy,temp,i,j,n;
	long long int answer;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		arr=(int**)malloc(sizeof(int*)*n);
		for(i=0;i<n;i++)
			arr[i]=(int*)malloc(sizeof(int)*n);
		
		x=(int**)malloc(sizeof(int*)*n);
		for(i=0;i<n;i++)
			x[i]=(int*)malloc(sizeof(int)*n);
		
		y=(int**)malloc(sizeof(int*)*n);
		for(i=0;i<n;i++)
			y[i]=(int*)malloc(sizeof(int)*n);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&arr[i][j]);
				temp=arr[i][j]-1;
				x[temp/n][temp%n]=i;
				y[temp/n][temp%n]=j;
			}
		}
		/*
		printf("Printing Data\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d,%d ",x[i][j],y[i][j]);
			printf("\n");
		}
		*/
		answer=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==0 && j==0)
				{
					prevx=x[i][j];
					prevy=y[i][j];
				}
				else
				{
					answer+=abs(x[i][j]-prevx);
					answer+=abs(y[i][j]-prevy);
					prevx=x[i][j];
					prevy=y[i][j];
				}
			}
		}
		printf("%lld\n",answer);
		free(x);
		free(y);
		free(arr);
	}
	return 0;
}
