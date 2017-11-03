#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int dist; // shortest distance from the source
		int nodeNumber;
		list<int> parentList; // this will store the list of all the parent nodes (for dijkstras algorithm)
		list<pair<int,int> >adjList; // first represents the adjacent node number and second represents the edge weight.
		Node(){}
		Node(int i)
		{
			nodeNumber=i;
			dist=INT_MAX;
		}

};
bool operator<(const Node&a,const Node&b)
{
	if(a.dist!=b.dist)
		return a.dist<b.dist;
	else return a.nodeNumber<b.nodeNumber;
}
class Graph
{
	public:
		vector<Node>nodes;
		Graph(){}
		Graph(int n)
		{
			for(int i=0;i<n;i++)
				nodes.push_back(Node(i));
		}
		void addEdge(int u,int v,int edgeWeight)
		{
			nodes[u].adjList.push_back(make_pair(v,edgeWeight));
		}
		void relax(int u,int v,int edgeWeight,set<Node>&s)
		{
			if(nodes[v].dist>nodes[u].dist+edgeWeight)
			{
				set<Node>::iterator it;
				for(it=s.begin();it!=s.end();it++)
					if(it->nodeNumber==v)
						break;
				if(it==s.end())
					cout<<"there is something wrong with the code."<<endl;
				else
				{
					nodes[v].dist=nodes[u].dist+edgeWeight;
					nodes[v].parentList=list<int>(); // erasing the previous list.
					nodes[v].parentList.push_back(u); // only one parent.
					s.erase(it);
					s.insert(nodes[v]);
				}
			}
			else if(nodes[v].dist==nodes[u].dist+edgeWeight)
			{
				nodes[v].parentList.push_back(u); // adding u to the parent list of v
			}
		}
		void dijkstras(int source) // this function will update dist and parent list of each node.
		{
			set<Node>s; // will be used as priority queue;
			// to update the value in the set, I'll delete and reinsert that item with updated value.
			// searching will take O(n) for a node. and deleting will take O(log n)
			nodes[source].dist=0;
			for(int i=0;i<nodes.size();i++)
				s.insert(nodes[i]);
			while(s.size()!=0)
			{
				Node u=*(s.begin());
				s.erase(s.begin());
				for(list<pair<int,int> >::iterator it=u.adjList.begin();it!=u.adjList.end();it++)
					relax(u.nodeNumber,it->first,it->second,s);
			}
		}
		void print()
		{
			cout<<"_____________________________________________________________\n";
			for(int i=0;i<nodes.size();i++)
			{
				cout<<"Node: "<<i<<"  shortest dist = "<<nodes[i].dist<<" => ";
				for(list<pair<int,int> >::iterator it=nodes[i].adjList.begin();it!=nodes[i].adjList.end();it++)
					cout<<"("<<it->first<<","<<it->second<<") ";	
				cout<<"\n";
			}
			cout<<"_____________________________________________________________\n";
		}
};
int gi(int i,int j,int n,int m) // get index
{
	return i*m+j;
}
void solve(int n,int m,vector<vector<int> >&pf,vector<vector<int> >&pt)
{
	Graph graph(n*m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i-1>=0) graph.addEdge(gi(i,j,n,m),gi(i-1,j,n,m),pf[i-1][j]);
			if(i+1<n) graph.addEdge(gi(i,j,n,m),gi(i+1,j,n,m),pf[i+1][j]);
			if(j-1>=0) graph.addEdge(gi(i,j,n,m),gi(i,j-1,n,m),pf[i][j-1]);
			if(j+1<m) graph.addEdge(gi(i,j,n,m),gi(i,j+1,n,m),pf[i][j+1]);
		}
	}
	graph.dijkstras(0);
	//graph.print();	
	Graph newGraph(n*m);
	for(int i=0;i<graph.nodes.size();i++)
	{
		for(list<int>::iterator it=graph.nodes[i].parentList.begin();it!=graph.nodes[i].parentList.end();it++)
		{
			int u=*it;
			int v=graph.nodes[i].nodeNumber;
			int ux=u/m;
			int uy=u%m;
			int vx=v/m;
			int vy=v%m;

			newGraph.addEdge(u,v,pt[vx][vy]);
		}
	}
	newGraph.dijkstras(0);
	int answer1=graph.nodes[n*m-1].dist+pf[0][0];
	int answer2=newGraph.nodes[n*m-1].dist+pt[0][0];
	cout<<answer1<<" "<<answer2<<endl;
}
int main()  
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<int> >pf(n,vector<int>(m,0));
		vector<vector<int> >pt(n,vector<int>(m,0));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>pf[i][j];

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>pt[i][j];
		solve(n,m,pf,pt);	
	}
	return 0;
}
