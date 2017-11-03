#include<stdio.h>
#include<utility>
#include<vector>
#include<map>
using namespace std;
map< int,vector< pair<int,int> > >graph;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		graph.erase(graph.begin(),graph.end());
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			vector< pair<int,int> >a;
			graph[i]=a;
		}
		for(int i=0;i<m;i++)
		{
			int a,b,d;
			scanf("%d%d%d",&a,&b,&d);
			graph[a].push_back(make_pair(b,d));
			graph[b].push_back(make_pair(a,d));
		}
		/*
		   for(int i=1;i<=n;i++)
		   {
		   printf("%d => ",i);
		   for(int j=0;j<graph[i].size();j++)
		   printf("(%d,%d)  ",graph[i][j].first,graph[i][j].second);
		   printf("\n");
		   }
		 */
		int min=202;
		for(int i=1;i<=n;i++)
		{
			int min1=101;int min2=101;
			for(int j=0;j<graph[i].size();j++)
			{
				if(graph[i][j].second<=min1)
				{
					min2=min1;
					min1=graph[i][j].second;
				}
				else if(graph[i][j].second<=min2)
					min2=graph[i][j].second;
			}
			//printf("%d = %d\n",i,min1+min2);
			if(min1!=101 && min2!=101 && min1+min2<min)
				min=min1+min2;
		}
		printf("%d\n",min);
	}
	return 0;
}
