#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,**arr,maxi,maxj,i,j,a,b,max,**flag;
	scanf("%d",&n);
	arr=(int**)malloc(sizeof(int*)*n);
	flag=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		arr[i]=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		flag[i]=(int*)malloc(sizeof(int)*n);
	max=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			flag[i][j]=0;
			scanf("%d",&arr[i][j]);
			if(arr[i][j]>max)
			{
				max=arr[i][j];
				maxi=i;maxj=j;
			}
		}
	}
	for(i=0;i<(n*(n-1))/2 && max!=0;i++)
	{
		flag[maxi][maxj]=1;
		printf("%d %d\n",maxi+1,maxj+1);
		fflush(stdout);
		scanf("%d%d",&a,&b);
		a--;b--;
		flag[a][b]=1;
		max=0;
		for(j=0;j<n;j++)
		{
			if(arr[b][j]>max && flag[b][j]==0)
			{
				max=arr[b][j];
				maxi=b;maxj=j;
			}
		}
	}
	return 0;
}
