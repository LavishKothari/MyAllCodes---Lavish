#include<utility>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
#define INF 10000000000000000
typedef long long int ll;
struct Edge*edges;
int m,n,mat[3001][3001];
vector< vector< pair<int,int> > > tree(3001);
struct Edge
{
	int start,end,w;
};
int cmp(const void*a,const void*b)
{
	return (*(struct Edge*)a).w-(*(struct Edge*)b).w;
}

int isThereAPath(int x,int y)
{
	vector<int>stack;
	stack.push_back(x);
	int *isVisited;
	isVisited=new int[n];
	for(int i=0;i<n;i++)
		isVisited[i]=false;
	
	while(stack.size()!=0)
	{
		int u=stack[0];
		stack.erase(stack.begin());
		for(int i=0;i<tree[u].size();i++)
		{
			int v=tree[u][i].first;
			if(isVisited[v]==false)
			{
				stack.push_back(v);
				isVisited[v]=true;
				if(v==y)
				{
					delete[]isVisited;
					return true;
				}
			}
		}
	}
	delete[]isVisited;
	return false;
}
int kruskal()
{
	int i,j;ll sum=0;
	int counter=0;i=0;
	while(counter!=m-1 && i<m)
	{
		if(!isThereAPath(edges[i].start,edges[i].end))
		{
			tree[edges[i].start].push_back(make_pair(edges[i].end,mat[edges[i].start][edges[i].end]));
			tree[edges[i].end].push_back(make_pair(edges[i].start,mat[edges[i].start][edges[i].end]));
			counter++;
		}
		i++;
	}
	for(i=0;i<n;i++)
		for(j=0;j<tree[i].size();j++)
			sum+=tree[i][j].second;
	return sum/2;
}
int main()
{
	int start,t,i,j,x,y,wt;
	{
		scanf("%d%d",&n,&m);
		edges=(struct Edge*)malloc(sizeof(struct Edge)*m);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=-1;
		for(i=0;i<m;i++)
		{
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
			/*
			edges[i].start=x-1;
			edges[i].end=y-1;
			edges[i].w=wt;
			*/
		}
		
		m=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(mat[i][j]!=-1)m++;
		m/=2;
		int counter=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(mat[i][j]!=-1)
				{
					edges[counter].start=i;
					edges[counter].end=j;
					edges[counter].w=mat[i][j];
					counter++;
				}
		/*
		for(int i=0;i<m;i++)
			printf("%d %d %d\n",edges[i].start+1,edges[i].end+1,edges[i].w);
		*/
		qsort(edges,m,sizeof(struct Edge),cmp);
		scanf("%d",&start);
		printf("%d",kruskal());
		
		free(edges);
	}
	
	return 0;
}
