#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

class vertex {
	public:
	int start,end,color,id,number_of_paths;
	vector <int> adj;
	vertex()
	{
		start=end=-1;
		number_of_paths=color=0;
		adj=vector<int>(0);
	}

};


void dfs(vector <vertex> &v, int n, int m, int start) {
	static int cnt=1;

	v[start].color = 1;
	v[start].start = cnt;
	cnt++;
		
	for(int i=0; i<v[start].adj.size(); i++) {
		int temp = v[start].adj[i];
		if(v[temp].color == 0)
			dfs(v,n,m,temp);
	}
		
	v[start].end = cnt;
	cnt++;
}

bool cmp(const vertex&a,const vertex &b)
{
	return b.end<a.end;
}

class Compare
{
	public:
	bool operator()(vertex&a,vertex&b)
	{
		return a.end<b.end;
	}
};
int getVertexWithID(vector<vertex>&graph,int id)
{
	for(int i=0;i<graph.size();i++)
		if(graph[i].id==id)
			return i;
	return -1;
}
int count_paths(vector<vertex>&graph,int start,int finish)
{
	priority_queue<vertex, vector<vertex>, Compare >Q;
	
	vector<bool>isvisited(graph.size(),false);

	int nstart=getVertexWithID(graph,start);
	graph[nstart].number_of_paths=1;
	Q.push(graph[nstart]);
	
	isvisited[nstart]=true;
	while(!Q.empty())
	{
		int current=Q.top().id;
		int ncurrent=getVertexWithID(graph,current);
		Q.pop();

		cout<<"this element is popped : "<<graph[ncurrent].id<<endl;

		for(int i=0;i<graph[ncurrent].adj.size();i++)
		{
			int adj=graph[ncurrent].adj[i];
			int nadj=getVertexWithID(graph,adj);
			graph[nadj].number_of_paths+=graph[ncurrent].number_of_paths;
			if(isvisited[nadj]==false)
			{
				Q.push(graph[nadj]);
				isvisited[nadj]=true;
			}
		}
	}
	
	return graph[getVertexWithID(graph,finish)].number_of_paths;
}

int main () {	
	// indexing of vertices is from 0
	int n,m;
	scanf("%d",&n);

	scanf("%d",&m);

	vector <vertex> v(n, vertex());
	for(int i=0;i<n;i++)
		v[i].id=i;
	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		v[a].adj.push_back(b);
	}
	int start,end;
	cin>>start>>end;
	dfs(v,n,m,start);
	/*
	for(int i=0;i<n;i++){
		cout<<i<<" : ";
		for(int j=0;j<v[i].adj.size();j++)
			cout<<v[i].adj[j]<<" ";
		cout<<" start = "<<v[i].start<<" and end = "<<v[i].end<<endl;
		cout<<endl;
	}
	*/
	sort(v.begin(),v.end(),cmp); // sorting the vertices according to the finish time.
	cout<<"graph in topological order : ";
	for(int i=0;i<n;i++)
		cout<<v[i].id<<" ";
	cout<<endl;
	
	cout<<"number of paths = "<<count_paths(v,start,end)<<endl;	
	return 0;
}
