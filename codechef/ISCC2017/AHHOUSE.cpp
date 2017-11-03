#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:

		vector<pair<int,int> >adjlist; // first represents the node number and second represents the edge weight.
		vector<int>parentlist;
		int dist,nodeNumber;
		Node(){}
		Node(int i)
		{
			dist=INT_MAX;
			nodeNumber=i;
		}
};
int gi(int i,int j,int n,int m) // get index
{
	return i*n+j;
}
class Compare
{
	public:
		bool operator()(Node&a, Node&b)
		{
			return a.dist < b.dist;
		}
};
class Priority_Queue
{
	public:
		vector<Node*>nodes;	
		Node* top()
		{
			int mini=INT_MAX;
			Node *answer=NULL;
			for(int i=0;i<nodes.size();i++)
			{
				if(nodes[i]->dist<mini)
				{
					mini=nodes[i]->dist;
					answer=nodes[i];
				}
			}
			return answer;
		}
		void pop()
		{
			int mini=INT_MAX;
			int index=-1;
			for(int i=0;i<nodes.size();i++)
			{
				if(nodes[i]->dist<mini)
				{
					mini=nodes[i]->dist;
					index=i;
				}
			}
			if(index!=-1)
			{
				nodes.erase(nodes.begin()+index);
			}
		}
		void push(Node* n)
		{
			nodes.push_back(n);
		}
		bool empty()
		{
			return (nodes.size()==0);
		}

};
void relax(int u,int v,vector<Node>&graph,vector<vector<int> >&pf)
{ 
	int n=pf.size();
	int pfvalue=pf[v/n][v%n];
	if(graph[v].dist>graph[u].dist+pfvalue)
	{
		graph[v].dist=graph[u].dist+pfvalue;
		graph[v].parentlist=vector<int>();
		graph[v].parentlist.push_back(u);
	}
	else if(graph[v].dist==graph[v].dist+pfvalue)
		graph[v].parentlist.push_back(u);
}
void dijkstra(int start,vector<Node>&graph,vector<vector<int> >&pf)
{
	cout<<"start  = "<<start<<endl;
	Priority_Queue pq;
	graph[start].dist=0;
	for(int i=0;i<graph.size();i++)
		pq.push(&graph[i]);
	cout<<"after pushing all the pointers in priority queue\n";
	set<int>completed;
	while(!pq.empty())
	{
		cout<<"in while loop "<<pq.nodes.size()<<endl;
		Node *current=pq.top();
		if(!current)
			break;
		pq.pop();
		completed.insert(current->nodeNumber);
		cout<<"this is the current index number = "<<current->nodeNumber<<endl;
		for(int i=0;i<current->adjlist.size();i++)
			if(completed.find(current->adjlist[i].first)==completed.end())
				relax(current->nodeNumber,current->adjlist[i].first,graph,pf);
	}
	cout<<"at the end of dijkstras\n";
}
void solve(int n,int m,vector<vector<int> >&pf,vector<vector<int> >&pt)
{
	vector<Node>graph(n*m);
	for(int i=0;i<n*m;i++)
		graph[i]=Node(i);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i-1>=0) graph[gi(i,j,n,m)].adjlist.push_back(make_pair(gi(i-1,j,n,m),pf[i-1][j]));
			if(i+1<n) graph[gi(i,j,n,m)].adjlist.push_back(make_pair(gi(i+1,j,n,m),pf[i+1][j]));
			if(j-1>=0) graph[gi(i,j,n,m)].adjlist.push_back(make_pair(gi(i,j-1,n,m),pf[i][j-1]));
			if(j+1<m) graph[gi(i,j,n,m)].adjlist.push_back(make_pair(gi(i,j+1,n,m),pf[i][j+1]));
		}
	}
	cout<<"this is before dijkstras"<<endl;
	dijkstra(0,graph,pf);
	for(int i=0;i<graph.size();i++)
	{
		cout<<"x,y = "<<i/n<<","<<i%n<<" : ";
		for(int j=0;j<graph[i].parentlist.size();j++)
		{
			cout<<graph[i].parentlist[j]<<" ";
		}
		cout<<"\t\t and dist = "<<graph[i].dist;
		cout<<"\n";
	}

	//dijkstras successful.
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
