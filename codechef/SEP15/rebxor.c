#include<stdio.h>
#include<stdlib.h>
int **maxxor,**start;
int main()
{
	int n,*arr,i,j,k;
	int max;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	maxxor=(int**)malloc(sizeof(int*)*n);
	start=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
	{
		maxxor[i]=(int*)malloc(sizeof(int)*n);
		start[i]=(int*)malloc(sizeof(int)*n);	
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		maxxor[i][i]=arr[i];
		start[i][i]=i;
	}
	for(j=0;j<n-1;j++)
	{
		for(i=j+1;i<n;i++)
		{
			if((maxxor[j][i-1]^arr[i])>arr[i])
			{
				maxxor[j][i]=(maxxor[j][i-1]^arr[i]);
				start[j][i]=start[j][i-1];
			}
			else
			{
				maxxor[j][i]=arr[i];
				start[j][i]=i;
			}
		}
	}
	/*
	for(i=0;i<n;i++)
		printf("%lld ",maxxor[i]);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%lld ",start[i]);
	printf("\n");
	*/
	max=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			//if(start[i+1][j]>i)
			{
				if(maxxor[0][i]+maxxor[i+1][j]>max)
				{
					//printf("%d %d\n",i,j);
					max=maxxor[0][i]+maxxor[i+1][j];
				}
			}
		}
	}
	/*if(n==2)
		max=arr[0]+arr[1];
	*/
	printf("%d\n",max);
	return 0;
}

