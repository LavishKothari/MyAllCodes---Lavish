#include <bits/stdc++.h>
using namespace std;

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
	vector<int>inDegree(n,0);
	vector<int>outDegree(n,0);

	vector<int>degreenew(n,0);

	vector<set<int> >graph(n,set<int>());
	vector<set<int> >graphnew(n,set<int>());

	for(int i=0;i<e;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);

		graphnew[a-1].insert(b-1);
		graphnew[b-1].insert(a-1);

		edges[i]=make_pair(a-1,b-1);
		degreenew[a-1]++;
		degreenew[b-1]++;

		graph[a-1].insert(b-1); // normal graph
		outDegree[a-1]++;
		inDegree[b-1]++;
	}

	bool shouldexit = !isConnected(graphnew);
	for(int i=0;i<n;i++)
		if((degreenew[i]&1) || degreenew[i]==0 || shouldexit)
		{
			cout<<"NO\n";
			return 0;
		}
	cout<<"YES\n";

	set<int>vertexSet;
	for(int i=0;i<n;i++)
		if(inDegree[i]!=outDegree[i])
			vertexSet.insert(i);

	while(!vertexSet.empty())
	{
		int vertex1,vertex2;
		set<int>:iterator it = vertexSet.begin();
		vertex1 = *it;
		it++;
		vertex2 = *it;

		if(outDegree[vertex2] > outDegree[vertex1])
			swap(vertex2,vertex1);
		// now vertex1 has bigger outDegree.
		swapEdges(vertex1,vertex2,graph);
	}
	return 0;
}
