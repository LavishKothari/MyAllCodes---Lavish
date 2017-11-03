/*
https://www.codechef.com/problems/TUX02
graph problem
concepts involved:
1) Topological ordering of graph
2) Strongly connected components
 */

#include<bits/stdc++.h>
using namespace std;
class Vertex
{
	public:
		int group; // represents the component number 
		int d,f,vn; // discovery time, finishing time and vertex number
		bool isVisited; 
		vector<int>adj_list; // adjacency list
		Vertex()
		{
			group=-1;
			d=f=0;
			isVisited=false;
			adj_list=vector<int>();
		}
};


// helper function for DFS
void dfsVisit(vector<Vertex>&G,int start,int &time,int g)
{
	G[start].group=g;
	time++;
	G[start].d=time;
	G[start].isVisited=true;
	for(int i=0;i<G[start].adj_list.size();i++)
	{
		int v=G[start].adj_list[i];
		if(!G[v].isVisited)
			dfsVisit(G,v,time,g);
	}
	time++;
	G[start].f=time;
}

// this function returns the number of dfs trees
// order specifies the order in which the vertices should be visited
int dfs(vector<Vertex>&G,vector<int>&order) 
{

	int n=G.size();
	int time=0;int group=0;
	for(int i=0;i<n;i++)
		G[i].isVisited=false; // isVisited of every vertex should be false
	for(int i=0;i<n;i++)
		if(!G[order[i]].isVisited)
		{
			dfsVisit(G,order[i],time,group);
			group++;
		}
	return group; // returns the number of dfs trees
}

bool cmp(const Vertex&a,const Vertex&b)
{
	return a.f>b.f; // sorting vertices on the basis of finishing time.
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<Vertex>G(n,Vertex()); // original graph
	vector<Vertex>GT(n,Vertex()); // transpose of original graph.
	for(int i=0;i<n;i++)
		G[i].vn = GT[i].vn = i; // initializing the vertex number.
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x-1].adj_list.push_back(y-1);
		GT[y-1].adj_list.push_back(x-1);
	}
	vector<int>order(n);
	for(int i=0;i<n;i++)
		order[i]=i;
	dfs(G,order); // updating the finishing time

	vector<Vertex>GC = G;
	sort(GC.begin(),GC.end(),cmp); // sorting on the basis of finishing time
	for(int i=0;i<n;i++)
		order[i]=GC[i].vn;

	dfs(GT,order); // dfs -> decreasing order of the finishing time

	int groups=0; // group represents the number of components of the graph
	for(int i=0;i<n;i++)
	{
		G[i].group = GT[i].group;
		if(GT[i].group>groups)
			groups = GT[i].group;
	}
	groups++;
	// groups now contain the number of components in graph.
	vector<set<int> >C(groups,set<int>());

	for(int i=0;i<n;i++)
	{
		int u=G[i].vn;
		for(int j=0;j<G[i].adj_list.size();j++)
		{
			int v=G[i].adj_list[j];
			C[G[u].group].insert(G[v].group);
		}
	}

	vector<Vertex>CO(groups,Vertex());
	for(int i=0;i<groups;i++)
		for(set<int>::iterator it=C[i].begin();it!=C[i].end();it++)
			if(*it!=i) // to remove self loops
				CO[i].adj_list.push_back(*it);
	for(int i=0;i<groups;i++)
		order[i]=i;
	dfs(CO,order);

	// finding the node in component graph with largest finish time
	int lar_fis=-1,fis_time=0;
	for(int i=0;i<groups;i++)
	{
		if(CO[i].f>fis_time)
		{
			fis_time = CO[i].f;
			lar_fis=i; // largest finishing component
		}
	}
	// updating the order so that the node with largest finish_time is chosen first
	swap(order[lar_fis],order[0]);
	int x=dfs(CO,order);
	if(x!=1) // if the number of dfs tree is not equal to 1
		printf("-1\n");
	else
	{
		int count=0;
		for(int i=0;i<n;i++)
			if(G[i].group == lar_fis)
				count++;
		printf("%d\n",count);
		for(int i=0;i<n;i++)
			if(G[i].group == lar_fis)
				printf("%d ",G[i].vn+1);
		cout<<endl;
	}
	return 0;
}
