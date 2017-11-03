#include<stdio.h>
#define INF 10000000000000000
typedef long long int ll;
int m,n,mat[3001][3001];
void dijkstras(int start)
{
	ll *dist;
	bool *isVisited;
	dist=new ll[n];
	isVisited=new bool[n];
	for(int i=0;i<n;i++)
	{
		isVisited[i]=false;
		dist[i]=INF;
	}	
	dist[start]=0;

	int cstart=start;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n;j++)
			if(mat[start][j]!=-1 && dist[j]>dist[start]+mat[start][j] && isVisited[j]==false)
				dist[j]=dist[start]+mat[start][j];
		isVisited[start]=true;
		ll min=INF,minindex;
		int j;
		for(j=0;j<n;j++)
			if(isVisited[j]==false && dist[j]<min)
			{
				min=dist[j];
				minindex=j;
			}
		start=minindex;
	}

	for(int i=0;i<n;i++)
	{
		if(i==cstart)
			continue;
		if(dist[i]!=INF)
			printf("%lld ",dist[i]);
		else if(dist[i]==INF)
			printf("-1 ");
	}
	printf("\n");
	delete []dist;
	delete []isVisited;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				mat[i][j]=-1;
		for(int i=0;i<m;i++)
		{
			int x,y,wt;
			scanf("%d%d%d",&x,&y,&wt);
			if(mat[x-1][y-1]==-1)
			{
				mat[x-1][y-1]=wt;
				mat[y-1][x-1]=wt;
			}
			else if(mat[x-1][y-1]>wt)
			{
				mat[x-1][y-1]=wt;
				mat[y-1][x-1]=wt;	
			}
		}
		int start;
		scanf("%d",&start);
		prims(start-1);
	}

	return 0;
}
