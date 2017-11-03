#include <bits/stdc++.h>
using namespace std;

set<pair<int,int> >markedEdges;

void dfs(int start,int currentVertex,vector<set<int> >&graph,vector<int>&degree,set<pair<int,int> >&newedges,set<int>&vertexSet)
{
	for(set<int>::iterator it=graph[currentVertex].begin();it!=graph[currentVertex].end();it++)
	{
		int u=currentVertex,v=*it;
		if(markedEdges.find(make_pair(u,v))!=markedEdges.end())
			continue;
		degree[u]--;
		degree[v]--;
		if(!degree[u])
			vertexSet.erase(u);
		if(!degree[v])
			vertexSet.erase(v);
		markedEdges.insert(make_pair(u,v));
		markedEdges.insert(make_pair(v,u));

		newedges.insert(make_pair(u,v));
		if(v!=start)
			dfs(start,v,graph,degree,newedges,vertexSet);
	}
}

bool isConnected(vector<set<int> >&graph)
{
	int n=graph.size();
	int start = 0;
	vector<bool>isVisited(n,false);

	list<int>q;
	q.push_front(start);
	isVisited[start]=true;

	while(!q.empty())
	{
		int u=q.front();
		q.pop_front();

		for(set<int>::iterator it=graph[u].begin();it!=graph[u].end();it++)
		{
			int v = *it;
			if(!isVisited[v])
			{
				isVisited[v]=true;
				q.push_front(v);
			}
		}
	}

	for(int i=0;i<n;i++)
		if(!isVisited[i])
			return false;
	return true;
}

int main() 
{
	int n,e;
	scanf("%d%d",&n,&e);
	vector<pair<int,int> >edges(e);
	vector<int>degree(n,0);
	vector<int>degreenew(n,0);

	vector<set<int> >graph(n,set<int>());
	vector<set<int> >graphnew(n,set<int>());
	set<pair<int,int> >edgeset;

	for(int i=0;i<e;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);

		graphnew[a-1].insert(b-1);
		graphnew[b-1].insert(a-1);

		edges[i]=make_pair(a-1,b-1);
		degreenew[a-1]++;
		degreenew[b-1]++;

		if(edgeset.find(make_pair(a-1,b-1))!=edgeset.end())
		{
			graph[a-1].erase(b-1);
			graph[b-1].erase(a-1);

			degree[a-1]--;
			degree[b-1]--;

			edgeset.erase(make_pair(a-1,b-1));
			edgeset.erase(make_pair(b-1,a-1));
			continue;
		}
		edgeset.insert(make_pair(a-1,b-1));
		edgeset.insert(make_pair(b-1,a-1));

		graph[a-1].insert(b-1);
		graph[b-1].insert(a-1);

		degree[a-1]++;
		degree[b-1]++;
	}

	bool shouldexit = !isConnected(graphnew);
	for(int i=0;i<n;i++)
		if((degreenew[i]&1) || degreenew[i]==0 || shouldexit)
		{
			cout<<"NO\n";
			return 0;
		}

	set<int>v;
	for(int i=0;i<n;i++)
		if(degree[i])
			v.insert(i);

	set<pair<int,int> >newedges;
	while(!v.empty())
	{
		int currentVertex=*(v.begin());
		dfs(currentVertex,currentVertex,graph,degree,newedges,v);
	}
	cout<<"YES\n";
	for(int i=0;i<e;i++)
	{
		if(newedges.find(edges[i]) == newedges.end())
			cout<<edges[i].second+1<<" "<<edges[i].first+1<<endl;
		else cout<<edges[i].first+1<<" "<<edges[i].second+1<<endl;
	}
	return 0;
}
