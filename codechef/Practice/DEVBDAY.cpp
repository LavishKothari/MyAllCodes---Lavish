#include<bits/stdc++.h>
using namespace std;
class Vertex
{
	public:
		bool isVisited;
		int inDegree;
		int bf,r;
		Vertex()
		{
			isVisited=false;
			inDegree=0;
			bf=-1;
			isInCycle=false;
		}
};

void dfsVisit(vector<Vertex>&G,int start,int &time,int &flag)
{	
	for(int i=0;i<G[start].adj_list;i++)
	{
		v=G[start][i];
		if(!G[v].isVisited)
			dfsVisit(G,v);
		else if(flag==0){
			G[v].isInCycle=true;
			flag=1;
		}
	}
}

void dfs(vector<Vertex>&G)
{
	int time=0;
	for(int i=0;i<G.size();i++)
		G[i].isVisited=false;
	for(int i=0;i<G.size();i++)
	{
		if(!G[i].isVisited)
		{
			int flag=0;
			dfsVisit(G,i);	
		}
	}	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<Vertex>G(n,Vertex());
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			G[i].bf=x-1;
			G[x-1].inDegree++;
		}
		for(int i=0;i<n;i++)
			scanf("%d",&G[i].r);

		dfs(G);

	}
	return 0;
}
