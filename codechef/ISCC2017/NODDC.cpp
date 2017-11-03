#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int dist; // shortest distance from the source
		int color;
		int nodeNumber;
		list<int> parentList; // this will store the list of all the parent nodes (for dijkstras algorithm)
		list<pair<int,int> >adjList; // first represents the adjacent node number and second represents the edge weight.
		Node(){}
		Node(int i)
		{
			nodeNumber=i;
			color=-1;
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
		void addEdge(int u,int v,int edgeWeight=1)
		{ // making an undirected graph
			nodes[u].adjList.push_back(make_pair(v,edgeWeight));
			nodes[v].adjList.push_back(make_pair(u,edgeWeight));
		}
		void removeEdge(int u,int v)
		{
			list<pair<int,int> >::iterator it;
			for(it=nodes[u].adjList.begin();it!=nodes[u].adjList.end();it++)
				if(it->first==v)
					break;
			if(it!=nodes[u].adjList.end())
				nodes[u].adjList.erase(it);

			for(it=nodes[v].adjList.begin();it!=nodes[v].adjList.end();it++)
				if(it->first==u)
					break;
			if(it!=nodes[v].adjList.end())
				nodes[v].adjList.erase(it);
		}
		bool isBipartite()
		{
			// by using a usual BFS
			vector<bool>isVisited(nodes.size(),false);
			queue<int>q;
			q.push(0);
			isVisited[0]=true;
			nodes[0].color=0;
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				for(list<pair<int,int> >::iterator it=nodes[u].adjList.begin();it!=nodes[u].adjList.end();it++)
				{
					int v=it->first;
					if(nodes[v].color == nodes[u].color)
						return false;
					if(isVisited[v])
						continue;	
					isVisited[v]=true;
					q.push(v);
					nodes[v].color=(!nodes[u].color);
				}
			} 
			return true;
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
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	Graph graph(n);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		a--;b--;
		graph.addEdge(a,b);
	}
	if(graph.isBipartite())
		cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
