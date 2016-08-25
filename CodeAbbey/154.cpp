#include<iostream>
#include<vector>
#include<set>
using namespace std;


void BFS(vector< set<int> > &graph,int n)
{
	vector<int>q;
	bool *isvisited=new bool[n];
	int *parent=new int[n];
	
	q.push_back(0);
	parent[0]=-1;
	isvisited[0]=1;
	
	while(!q.empty())
	{
		int u=*(q.begin());
		q.erase(q.begin());
		
		for(set<int>::iterator it=graph[u].begin();it!=graph[u].end();it++)
		{
			int v=*it;
			if(!isvisited[v])
			{
				q.push_back(v);
				isvisited[v]=1;
				parent[v]=u;
			}	
		}
	}
	for(int i=0;i<n;i++)
		cout<<parent[i]<<" ";
		
	delete parent;
	delete isvisited;
}

int main()
{
	int n,e;
	cin>>n>>e;
	
	vector< set<int> >graph(n);
	
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	
	BFS(graph,n);

	return 0;
}
