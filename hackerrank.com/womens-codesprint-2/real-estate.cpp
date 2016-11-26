// C++ program for implementation of Ford Fulkerson algorithm
#include <bits/stdc++.h>
using namespace std;
int V;
class Element
{
public:
	int price,area;
};



bool bfs(vector< vector<int> > &rGraph, int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    return (visited[t] == true);
}
 
int fordFulkerson(vector< vector<int> > &graph, int s, int t)
{
    int u, v;
    vector< vector<int> >rGraph(V,vector<int>(V,0)); 
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V];
 
    int max_flow = 0;  
 
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 	    for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        max_flow += path_flow;
    }
 
    return max_flow;
}

int main()
{
	int M,N;
	cin>>N>>M;

	V=M+N+2;

	vector< vector<int> >graph(V,vector<int>(V,0));

	vector<Element>client(N);
	vector<Element>house(M);
		
	for(int i=0;i<N;i++)
		cin>>client[i].area>>client[i].price;
	for(int j=0;j<M;j++)
		cin>>house[j].area>>house[j].price;

	for(int j=1;j<=N;j++) // from source to first N
		graph[0][j]=1;
	for(int i=0+N+1;i<M+N+1;i++) // from M to sink
		graph[i][V-1]=1;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(client[i].area<house[j].area && client[i].price>=house[j].price)
				graph[i+1][j+N+1]=1;
		}
	}
	/*
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cout<<graph[i][j];
		}
		cout<<endl;
	}
	*/
	cout<<fordFulkerson(graph, 0, V-1)<<endl;
	return 0;
}
