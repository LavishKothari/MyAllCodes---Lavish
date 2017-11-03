#include<bits/stdc++.h>
using namespace std;
bool BFS(vector< vector<int> >&graph,int start,vector<int>&color)
{
	//cout<<"bfs called on "<<start<<endl;
	color[start]=0;
	vector<int>Q;
	Q.push_back(start);

	while(!Q.empty())
	{
		int current=Q[0];
		Q.erase(Q.begin());

		for(int i=0;i<graph.size();i++)
		{
			if(graph[current][i]==1)
			{
				if(color[i]==-1)
				{
					color[i]=(!color[current]);
					Q.push_back(i);
				}
				else if(color[i]==color[current])
					return false;
			}
		}
	}
	return true;
}
bool isBipartite(vector< vector<int> >&graph)
{
	int n=graph.size();
	vector<int>color(n,-1); // -1 means uncolored.

	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
			if(!BFS(graph,i,color))
				return false;
		}
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector< vector<int> >graph(n,vector<int>(n,1));
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			if(a==b)
				continue;
			graph[a-1][b-1]=0;
			graph[b-1][a-1]=0;
		}
		for(int i=0;i<n;i++)
			graph[i][i]=0;
		isBipartite(graph)?cout<<"YES\n":cout<<"NO\n";	
	}
}
