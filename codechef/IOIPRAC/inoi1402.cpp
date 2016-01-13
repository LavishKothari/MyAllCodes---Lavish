#include<stdio.h>
#define INF 2147483647

int main()
{
	int c,f;
	scanf("%d%d",&c,&f);
	int **arr=new int*[c];
	for(int i=0;i<c;i++)
		arr[i]=new int[c];
	for(int i=0;i<c;i++)
		for(int j=0;j<c;j++)
			arr[i][j]=INF;
	for(int i=0;i<c;i++)
		arr[i][i]=0;
	for(int i=0;i<f;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		arr[x-1][y-1]=z;
		arr[y-1][x-1]=z;
	}
	for(int i=0;i<c;i++)
		for(int j=0;j<c;j++)
			for(int k=0;k<c;k++)
				if(arr[i][k]!=INF && arr[k][j]!=INF && arr[i][j]>arr[i][k]+arr[k][j])
				{
					arr[i][j]=arr[i][k]+arr[k][j];
				}
	int max=0;
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<c;j++)
		{
			//printf("%d ",arr[i][j]);
			if(arr[i][j]>max)
				max=arr[i][j];
		}
		//printf("\n");
	}
	printf("%d\n",max);
	return 0;
}
